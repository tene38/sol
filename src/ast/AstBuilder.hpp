#pragma once

#include <memory>

#include "antlr4-runtime.h"
#include "ast/Ast.hpp"
#include "parser/SolBaseVisitor.h"

namespace sol::ast
{

using sol::parser::SolParser;

class AstBuilder : public sol::parser::SolBaseVisitor
{
  public:
    std::unique_ptr<ProgramAst> Program;
    std::unique_ptr<ProcedureAst> Procedure;
    std::unique_ptr<ReturnStatementAst> ReturnStatement;
    std::unique_ptr<ExprAst> Expr;

    std::any visitProgram(SolParser::ProgramContext *context) override;
    std::any visitProcedure(SolParser::ProcedureContext *context) override;
    std::any
    visitReturnStatement(SolParser::ReturnStatementContext *context) override;
    std::any visitIdentExpr(SolParser::IdentExprContext *context) override;
    std::any visitCallExpr(SolParser::CallExprContext *context) override;
    std::any visitIntExpr(SolParser::IntExprContext *context) override;
    std::any visitBinopExpr(SolParser::BinopExprContext *context) override;
};

} // namespace sol::ast
