#include <iostream>

#include "ast/Ast.hpp"
#include "ast/AstPrinter.hpp"

namespace sol::ast
{

AstPrinter::AstPrinter(std::ostream &out) : Out(out), Depth(0)
{
}

void AstPrinter::visit(AstNode *ast) 
{
    ast->Accept(this);
}

std::string AstPrinter::Indent()
{
    std::string indent;

    int numSpaces = Depth * Shift;
    while (numSpaces-- > 0)
        indent += " ";
    return indent;
}

void AstPrinter::visit(ExprAst *ast) 
{
    ast->Accept(this);
}

void AstPrinter::visit(NumberExprAst *ast)
{
    Depth += 1;
    Out << Indent() << ast->GetVal() << std::endl;
    Depth -= 1;
}

void AstPrinter::visit(VariableExprAst *ast)
{
    Depth += 1;
    Out << Indent() << ast->GetName() << std::endl;
    Depth -= 1;
}

void AstPrinter::visit(BinaryExprAst *ast)
{
    Depth += 1;
    Out << Indent() << ast->GetOp() << std::endl;
    visit(ast->GetLHS().get());
    visit(ast->GetLHS().get());
    Depth -= 1;
}

void AstPrinter::visit(CallExprAst *ast)
{
    Depth += 1;
    Out << Indent() << ast->GetCallee() << std::endl;
    for (auto &arg : ast->GetArgs())
        visit(arg.get());
    Depth -= 1;
}

void AstPrinter::visit(ReturnStatementAst *ast)
{
    Depth += 1;
    Out << "return" << std::endl;
    visit(ast->GetReturnExpression().get());
    Depth -= 1;
}

void AstPrinter::visit(ProcedureAst *ast)
{
    Depth += 1;
    Out << "procedure " << ast->GetName() << "(";
    auto &args = ast->GetArgs();
    for (int size = args.size(), i = 0; i < size; ++i) {
        Out << args[i];
        if (i != size - 1)
            Out << ", ";
    }
    Out << ")" << std::endl;
    visit(ast->GetBody().get());
    Depth -= 1;
}

void AstPrinter::visit(ProgramAst *ast)
{
    for (auto &proc : ast->GetProcedures())
        visit(proc.get());
}

} // namespace sol::ast
