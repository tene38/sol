#include <iostream>

#include "ast/Ast.hpp"
#include "ast/AstPrinter.hpp"

namespace sol::ast
{

AstPrinter::AstPrinter(std::ostream &Out) : Out(Out), Depth(0)
{
}

std::string AstPrinter::indent()
{
    std::string indent;

    int numSpaces = Depth * SHIFT;
    while (numSpaces-- > 0)
        indent += " ";
    return indent;
}

void AstPrinter::visit(ExprAst *Ast)
{
    Ast->accept(this);
}

void AstPrinter::visit(AstNode *Ast)
{
    Ast->accept(this);
}

void AstPrinter::visit(NumberExprAst *Ast)
{
    Depth += 1;
    Out << indent() << Ast->getVal() << std::endl;
    Depth -= 1;
}

void AstPrinter::visit(VariableExprAst *Ast)
{
    Depth += 1;
    Out << indent() << Ast->getName() << std::endl;
    Depth -= 1;
}

void AstPrinter::visit(BinaryExprAst *Ast)
{
    Depth += 1;
    Out << indent() << Ast->getOp() << std::endl;
    visit(Ast->getLHS().get());
    visit(Ast->getRHS().get());
    Depth -= 1;
}

void AstPrinter::visit(CallExprAst *Ast)
{
    Depth += 1;
    Out << indent() << Ast->getCallee() << std::endl;
    for (auto &arg : Ast->getArgs())
        visit(arg.get());
    Depth -= 1;
}

void AstPrinter::visit(ReturnStatementAst *Ast)
{
    Depth += 1;
    Out << "return" << std::endl;
    visit(Ast->getReturnExpression().get());
    Depth -= 1;
}

void AstPrinter::visit(ProcedureAst *Ast)
{
    Depth += 1;
    Out << "procedure " << Ast->getName() << "(";
    auto &Args = Ast->getArgs();
    for (int Size = Args.size(), i = 0; i < Size; ++i) {
        Out << Args[i];
        if (i != Size - 1)
            Out << ", ";
    }
    Out << ")" << std::endl;
    visit(Ast->getBody().get());
    Depth -= 1;
}

void AstPrinter::visit(ProgramAst *Ast)
{
    for (auto &Proc : Ast->getProcedures())
        visit(Proc.get());
}

} // namespace sol::ast
