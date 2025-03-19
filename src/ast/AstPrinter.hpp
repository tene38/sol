#pragma once

#include <iostream>

#include "ast/AstVisitor.hpp"

namespace sol::ast
{

class AstPrinter : public AstVisitor
{
    // TODO: make this print proper S-exprs.
    std::ostream &Out;
    const int SHIFT = 4;
    int Depth;

    std::string indent();

  public:
    void visit(AstNode *Ast) override;
    void visit(ExprAst *Ast) override;
    void visit(NumberExprAst *Ast) override;
    void visit(VariableExprAst *Ast) override;
    void visit(BinaryExprAst *Ast) override;
    void visit(CallExprAst *Ast) override;
    void visit(ReturnStatementAst *Ast) override;
    void visit(ProcedureAst *Ast) override;
    void visit(ProgramAst *Ast) override;

    AstPrinter(std::ostream &Out);
};

} // namespace sol::ast
