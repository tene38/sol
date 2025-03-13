#include <print>

#include "antlr4-runtime.h"
#include "parser/SolLexer.h"
#include "parser/SolParser.h"
#include "parser/SolBaseListener.h"
#include "parser/SolBaseVisitor.h"

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
    std::println("{}", tree->toStringTree(&parser));


    // Build the AST

    // Generate the IR
}
