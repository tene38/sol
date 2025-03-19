#include <vector>
#include <string>

#include "ast/Ast.hpp"
#include "ast/AstVisitor.hpp"

// TODO: this file, and the corresponding `Ast.hpp` should be broken up into
// one file per class.

namespace sol::ast
{

NumberExprAst::NumberExprAst(int Val) : Val(Val)
{
}

VariableExprAst::VariableExprAst(const std::string &Name) : Name(Name)
{
}

BinaryExprAst::BinaryExprAst(const std::string &Op,
                             std::unique_ptr<ExprAst> LHS,
                             std::unique_ptr<ExprAst> RHS)
    : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS))
{
}

CallExprAst::CallExprAst(const std::string &Callee,
                         std::vector<std::unique_ptr<ExprAst>> Args)
    : Callee(Callee), Args(std::move(Args))
{
}

ReturnStatementAst::ReturnStatementAst(std::unique_ptr<ExprAst> ReturnExpr)
    : ReturnExpression(std::move(ReturnExpr))
{
}

ProcedureAst::ProcedureAst(const std::string &Name,
                           std::vector<std::string> &Args,
                           std::unique_ptr<ReturnStatementAst> Body)
    : Name(Name), Args(std::move(Args)), Body(std::move(Body))
{
}

ProgramAst::ProgramAst(std::vector<std::unique_ptr<ProcedureAst>> Procedures)
    : Procedures(std::move(Procedures))
{
}


void NumberExprAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void VariableExprAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void BinaryExprAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void CallExprAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void ReturnStatementAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void ProcedureAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}

void ProgramAst::accept(AstVisitor *Visitor)
{
    Visitor->visit(this);
}


int NumberExprAst::getVal()
{
    return Val;
}

std::string VariableExprAst::getName()
{
    return Name;
}

std::string BinaryExprAst::getOp()
{
    return Op;
}

std::unique_ptr<ExprAst> &BinaryExprAst::getLHS()
{
    return LHS;
}

std::unique_ptr<ExprAst> &BinaryExprAst::getRHS()
{
    return RHS;
}

std::string CallExprAst::getCallee()
{
    return Callee;
}

std::vector<std::unique_ptr<ExprAst>> &CallExprAst::getArgs()
{
    return Args;
}

std::unique_ptr<ExprAst> &ReturnStatementAst::getReturnExpression()
{
    return ReturnExpression;
}

std::string ProcedureAst::getName()
{
    return Name;
}

std::vector<std::string> &ProcedureAst::getArgs()
{
    return Args;
}

std::unique_ptr<ReturnStatementAst> &ProcedureAst::getBody()
{
    return Body;
}

std::vector<std::unique_ptr<ProcedureAst>> &ProgramAst::getProcedures()
{
    return Procedures;
}

} // namespace sol::ast
