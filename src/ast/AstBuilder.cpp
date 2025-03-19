#include "ast/AstBuilder.hpp"
#include "ast/Ast.hpp"

#include "antlr4-runtime.h"
#include <memory>

namespace sol::ast
{

std::any AstBuilder::visitProgram(SolParser::ProgramContext *context)
{
    std::vector<std::unique_ptr<ProcedureAst>> Procs;
    for (auto &Proc : context->procedure()) {
        visit(Proc);
        Procs.push_back(std::move(Procedure));
    }

    Program = std::make_unique<ProgramAst>(std::move(Procs));
    return 0;
}

std::any AstBuilder::visitProcedure(SolParser::ProcedureContext *context)
{
    std::string Name = context->IDENT()->getText();
    std::vector<std::string> Args;

    for (auto &Arg : context->args()->arg())
        Args.push_back(Arg->IDENT()->getText());

    visit(context->returnStatement());

    Procedure =
        std::make_unique<ProcedureAst>(Name, Args, std::move(ReturnStatement));

    return 0;
}

std::any
AstBuilder::visitReturnStatement(SolParser::ReturnStatementContext *context)
{
    visit(context->expression());

    ReturnStatement = std::make_unique<ReturnStatementAst>(std::move(Expr));
    return 0;
}

std::any AstBuilder::visitIdentExpr(SolParser::IdentExprContext *context)
{
    auto Ident = context->IDENT()->getText();
    Expr = std::make_unique<VariableExprAst>(Ident);
    return 0;
}

std::any AstBuilder::visitCallExpr(SolParser::CallExprContext *context)
{
    std::string Callee = context->IDENT()->getText();

    std::vector<std::unique_ptr<ExprAst>> Args;
    for (auto &Arg : context->expression()) {
        visit(Arg);
        Args.push_back(std::move(Expr));
    }

    Expr = std::make_unique<CallExprAst>(Callee, std::move(Args));
    return 0;
}

std::any AstBuilder::visitIntExpr(SolParser::IntExprContext *context)
{
    // By the grammar of the language, this should never fail.
    // Unless of course the definition of INT in the grammar is changed.
    auto V = std::stoi(context->INT()->getText());
    Expr = std::make_unique<NumberExprAst>(V);
    return 0;
}

std::any AstBuilder::visitBinopExpr(SolParser::BinopExprContext *context)
{
    std::string Op = context->op->getText();

    visit(context->expression(0));
    std::unique_ptr<ExprAst> LHS = std::move(Expr);
    visit(context->expression(1));
    std::unique_ptr<ExprAst> RHS = std::move(Expr);

    Expr = std::make_unique<BinaryExprAst>(Op, std::move(LHS), std::move(RHS));
    return 0;
}

} // namespace sol::ast
