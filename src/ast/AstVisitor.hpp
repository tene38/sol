#pragma once

#include "ast/Ast.hpp"

namespace sol::ast
{

class AstVisitor
{
  public:
    virtual void visit(AstNode *Ast) = 0;
    virtual void visit(ExprAst *Ast) = 0;
    virtual void visit(NumberExprAst *Ast) = 0;
    virtual void visit(VariableExprAst *Ast) = 0;
    virtual void visit(BinaryExprAst *Ast) = 0;
    virtual void visit(CallExprAst *Ast) = 0;
    virtual void visit(ReturnStatementAst *Ast) = 0;
    virtual void visit(ProcedureAst *Ast) = 0;
    virtual void visit(ProgramAst *Ast) = 0;
};

} // namespace sol::ast
