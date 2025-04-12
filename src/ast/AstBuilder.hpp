#pragma once

#include <memory>

#include "antlr4-runtime.h"
#include "ast/Ast.hpp"
#include "parser/SolBaseVisitor.h"

namespace sol::ast
{

class AstBuilder : public sol::parser::SolBaseVisitor
{
  public:
    std::unique_ptr<ProgramAst> Program;
    std::unique_ptr<ProcedureAst> Procedure;
    std::unique_ptr<ReturnStatementAst> ReturnStatement;
    std::unique_ptr<ExprAst> Expr;

    // I'm not a fan of RTTI and exceptions, but the ANTLR API uses them.
    std::any visitProgram(parser::SolParser::ProgramContext *context) override;
    std::any visitProcedure(parser::SolParser::ProcedureContext *context) override;
    std::any
    visitReturnStatement(parser::SolParser::ReturnStatementContext *context) override;
    std::any visitIdentExpr(parser::SolParser::IdentExprContext *context) override;
    std::any visitCallExpr(parser::SolParser::CallExprContext *context) override;
    std::any visitIntExpr(parser::SolParser::IntExprContext *context) override;
    std::any visitBinopExpr(parser::SolParser::BinopExprContext *context) override;
};

} // namespace sol::ast
