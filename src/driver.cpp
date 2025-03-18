#include <print>
#include <iostream>
#include <filesystem>

#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/IR/LegacyPassManager.h"

#include "antlr4-runtime.h"
#include "parser/SolLexer.h"
#include "parser/SolParser.h"
#include "ast/AstBuilder.hpp"
#include "ast/AstPrinter.hpp"
#include "ir/IRGenerator.hpp"
#include "ast/Ast.hpp"


namespace fs = std::filesystem;
namespace cl = llvm::cl;

// Commandline options
cl::opt<std::string> OutputFilename("o", cl::desc("Specify output filename"),
                                    cl::value_desc("filename"));
cl::opt<std::string> InputFilename(cl::Positional, cl::Required,
                                   cl::desc("<input file>"));
cl::opt<bool> Verbose("v", cl::desc("Enable verbose output"));
cl::opt<bool> Debug("g", cl::desc("Build with debug information (unimplemented yet)"));

int main(const int argc, const char *argv[])
{
    // Check commandline arguments
    cl::ParseCommandLineOptions(argc, argv);

    fs::path inputFile(InputFilename.c_str());

    if (Verbose) {
        std::println("Compiling {}.", inputFile.string());
    }

    // Run the parser
    std::ifstream inputFileStream(inputFile.string());

    antlr4::ANTLRInputStream inputStream(inputFileStream);

    sol::parser::SolLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    sol::parser::SolParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.program();

    if (Verbose) {
        std::println("Parsed:");
        std::println("{}", tree->toStringTree(&parser, true));
    }

    // If there were any errors, exit
    if (parser.getNumberOfSyntaxErrors() > 0)
        return -1;

    // Build the AST
    sol::ast::AstBuilder astBuilder;
    astBuilder.visit(tree);
    auto ast =
        std::unique_ptr<sol::ast::AstNode>(std::move(astBuilder.Program));

    if (Verbose) {
        auto astPrinter = sol::ast::AstPrinter(std::cout);
        astPrinter.visit(ast.get());
    }

    // Generate the IR
    auto moduleName = inputFile.filename().string();
    auto TheContext = std::make_unique<llvm::LLVMContext>();
    auto TheModule = std::make_unique<llvm::Module>(moduleName, *TheContext);
    auto TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);

    // TODO: all of the classes I defined have default:
    // 1. Destructors
    // 2. Copy operations (copy constructor, copy assignment operator)
    // 3. Move operations (move constructor, move assignment operaotr)
    // Go over every single one and make sure these operations make sense, or
    // they're deleted when they're not needed.
    auto irGenerator = sol::ir::IRGenerator(TheContext.get(), TheBuilder.get(),
                                            TheModule.get());
    irGenerator.visit(ast.get());

    if (Verbose) {
        TheModule->print(llvm::errs(), nullptr);
    }

    // Generate the binary
    auto targetTriple = llvm::sys::getDefaultTargetTriple();

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string error;
    auto target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        llvm::errs() << error;
        return 1;
    }

    auto cpu = "generic";
    auto features = "";
    llvm::TargetOptions opt;

    auto targetMachine = target->createTargetMachine(
        targetTriple, cpu, features, opt, llvm::Reloc::PIC_);

    TheModule->setDataLayout(targetMachine->createDataLayout());
    TheModule->setTargetTriple(targetTriple);

    std::string outputFile;
    if (OutputFilename.getNumOccurrences() != 0) {
        outputFile = OutputFilename.c_str();
    } else {
        outputFile = inputFile.filename().replace_extension(".o");
    }
    std::error_code EC;
    llvm::raw_fd_ostream dest(outputFile, EC, llvm::sys::fs::OF_None);

    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return 1;
    }

    llvm::legacy::PassManager pass;
    auto FileType = llvm::CodeGenFileType::ObjectFile;

    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        llvm::errs() << "TargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*TheModule);
    dest.flush();
}
