#include <print>
#include <cstdlib>
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
/* #include "lld/Driver/Common.h" */

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

    fs::path InputFilePath(InputFilename.c_str());

    if (Verbose) {
        std::println("Compiling {}.", InputFilePath.string());
    }

    // Run the parser
    std::ifstream InputFileStream(InputFilePath.string());
    antlr4::ANTLRInputStream AntlrInputStream(InputFileStream);

    sol::parser::SolLexer Lexer(&AntlrInputStream);
    antlr4::CommonTokenStream TokenStream(&Lexer);
    sol::parser::SolParser Parser(&TokenStream);

    antlr4::tree::ParseTree *ParseTree = Parser.program();

    if (Verbose) {
        std::println("Parsed:");
        std::println("{}", ParseTree->toStringTree(&Parser, true));
    }

    // If there were any errors, exit
    if (Parser.getNumberOfSyntaxErrors() > 0)
        return -1;

    // Build the AST
    sol::ast::AstBuilder AstBuilder;
    AstBuilder.visit(ParseTree);
    auto Ast =
        std::unique_ptr<sol::ast::AstNode>(std::move(AstBuilder.Program));

    if (Verbose) {
        auto AstPrinter = sol::ast::AstPrinter(std::cout);
        AstPrinter.visit(Ast.get());
    }

    // Generate the IR
    auto ModuleName = InputFilePath.filename().string();
    auto TheContext = std::make_unique<llvm::LLVMContext>();
    auto TheModule = std::make_unique<llvm::Module>(ModuleName, *TheContext);
    auto TheBuilder = std::make_unique<llvm::IRBuilder<>>(*TheContext);

    // TODO: all of the classes I defined have default:
    // 1. Destructors
    // 2. Copy operations (copy constructor, copy assignment operator)
    // 3. Move operations (move constructor, move assignment operaotr)
    // Go over every single one and make sure these operations make sense, or
    // they're deleted when they're not needed.
    auto IrGenerator = sol::ir::IRGenerator(TheContext.get(), TheBuilder.get(),
                                            TheModule.get());
    IrGenerator.visit(Ast.get());

    if (Verbose) {
        TheModule->print(llvm::errs(), nullptr);
    }

    // Generate object files
    auto TargetTriple = llvm::sys::getDefaultTargetTriple();

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string Error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    if (!Target) {
        llvm::errs() << Error;
        return 1;
    }

    auto Cpu = "generic";
    auto Features = "";
    llvm::TargetOptions Opt;

    auto TargetMachine = Target->createTargetMachine(
        TargetTriple, Cpu, Features, Opt, llvm::Reloc::PIC_);

    TheModule->setDataLayout(TargetMachine->createDataLayout());
    TheModule->setTargetTriple(TargetTriple);

    std::string ObjectFilename = InputFilePath.filename().replace_extension(".o");
    std::error_code EC;
    llvm::raw_fd_ostream ObjectOutputStream(ObjectFilename, EC, llvm::sys::fs::OF_None);

    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return 1;
    }

    llvm::legacy::PassManager Pass;
    auto FileType = llvm::CodeGenFileType::ObjectFile;

    if (TargetMachine->addPassesToEmitFile(Pass, ObjectOutputStream, nullptr, FileType)) {
        llvm::errs() << "TargetMachine can't emit a file of this type";
        return 1;
    }

    Pass.run(*TheModule);
    ObjectOutputStream.flush();

    // Run the linker
    // TODO: this is a very simplistic way of producing the binary.
    //  Invoke an actual linker instead, like `ld` or `lld`, and choose which
    //  language runtime libraries you actually need, or write your own.
    std::string ExecutableFilename;
    if (OutputFilename.getNumOccurrences() != 0)
        ExecutableFilename = OutputFilename.c_str();
    else
        ExecutableFilename = InputFilePath.filename().replace_extension("");

    auto ClangCommandline = std::format("clang -o {} {}", ExecutableFilename, ObjectFilename);

    if (Verbose) {
        std::println("Invoking: `{}`", ClangCommandline);
    }

    std::system(ClangCommandline.c_str());
}
