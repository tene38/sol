#pragma once

#include <iostream>

#include "ast/AstVisitor.hpp"

namespace sol::ast
{

class AstPrinter : public AstVisitor
{
    // TODO: make this print proper S-exprs.
    std::ostream &Out;
    const int Shift = 4;
    int Depth;

    std::string Indent();

  public:
    void visit(AstNode *ast) override;
    void visit(ExprAst *ast) override;
    void visit(NumberExprAst *ast) override;
    void visit(VariableExprAst *ast) override;
    void visit(BinaryExprAst *ast) override;
    void visit(CallExprAst *ast) override;
    void visit(ReturnStatementAst *ast) override;
    void visit(ProcedureAst *ast) override;
    void visit(ProgramAst *ast) override;

    AstPrinter(std::ostream &out);
};

} // namespace sol::ast
