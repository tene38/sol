#include <llvm/Support/raw_ostream.h>
#include <print>
#include <iostream>

#include "antlr4-runtime.h"
#include "parser/SolLexer.h"
#include "parser/SolParser.h"
#include "ast/AstBuilder.hpp"
#include "ast/AstPrinter.hpp"
#include "ir/IRGenerator.hpp"
#include "ast/Ast.hpp"

void PrintUsage(std::string programName)
{
    std::println("Usage: {} <input_file>", programName);
    std::println("Where:");
    std::println("    - <input_file>: .sol file to compile");
}

int main(const int argc, const char *argv[])
{

    // Check commandline arguments
    if (argc != 2) {
        PrintUsage(argv[0]);
        return -1;
    }

    std::println("Compiling {}.", argv[1]);

    // Run the parser
    std::ifstream inputFileStream(argv[1]);

    antlr4::ANTLRInputStream inputStream(inputFileStream);

    sol::parser::SolLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokens(&lexer);
    sol::parser::SolParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.program();

    std::println("Parsed:");
    std::println("{}", tree->toStringTree(&parser, true));

    // If there were any errors, exit
    if (parser.getNumberOfSyntaxErrors() > 0)
        return -1;

    // Build the AST
    sol::ast::AstBuilder astBuilder;
    astBuilder.visit(tree);
    auto ast =
        std::unique_ptr<sol::ast::AstNode>(std::move(astBuilder.Program));

    // TODO: AstPrinter is borked. Fix!
    auto astPrinter = sol::ast::AstPrinter(std::cout);
    astPrinter.visit(ast.get());

    // Generate the IR
    auto TheContext = std::make_unique<llvm::LLVMContext>();
    auto TheModule = std::make_unique<llvm::Module>(argv[1], *TheContext);
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

    TheModule->print(llvm::errs(), nullptr);

    // Generate the binary
}
