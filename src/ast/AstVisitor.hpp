#pragma once

#include "ast/Ast.hpp"

namespace sol::ast
{

class AstVisitor
{
  public:
    virtual void visit(ExprAst *ast) = 0;
    virtual void visit(NumberExprAst *ast) = 0;
    virtual void visit(VariableExprAst *ast) = 0;
    virtual void visit(BinaryExprAst *ast) = 0;
    virtual void visit(CallExprAst *ast) = 0;
    virtual void visit(ReturnStatementAst *ast) = 0;
    virtual void visit(ProcedureAst *ast) = 0;
    virtual void visit(ProgramAst *ast) = 0;
};

} // namespace sol::ast
