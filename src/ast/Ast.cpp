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


void NumberExprAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void VariableExprAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void BinaryExprAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void CallExprAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void ReturnStatementAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void ProcedureAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}

void ProgramAst::Accept(AstVisitor *visitor)
{
    visitor->visit(this);
}


int NumberExprAst::GetVal()
{
    return Val;
}

std::string VariableExprAst::GetName()
{
    return Name;
}

std::string BinaryExprAst::GetOp()
{
    return Op;
}

std::unique_ptr<ExprAst> &BinaryExprAst::GetLHS()
{
    return LHS;
}

std::unique_ptr<ExprAst> &BinaryExprAst::GetRHS()
{
    return RHS;
}

std::string CallExprAst::GetCallee()
{
    return Callee;
}

std::vector<std::unique_ptr<ExprAst>> &CallExprAst::GetArgs()
{
    return Args;
}

std::unique_ptr<ExprAst> &ReturnStatementAst::GetReturnExpression()
{
    return ReturnExpression;
}

std::string ProcedureAst::GetName()
{
    return Name;
}

std::vector<std::string> &ProcedureAst::GetArgs()
{
    return Args;
}

std::unique_ptr<ReturnStatementAst> &ProcedureAst::GetBody()
{
    return Body;
}

std::vector<std::unique_ptr<ProcedureAst>> &ProgramAst::GetProcedures()
{
    return Procedures;
}

} // namespace sol::ast
