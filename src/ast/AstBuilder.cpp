#include "ast/AstBuilder.hpp"
#include "ast/Ast.hpp"

#include "antlr4-runtime.h"
#include <memory>

namespace sol::ast
{

std::any AstBuilder::visitProgram(SolParser::ProgramContext *context)
{
    std::vector<std::unique_ptr<ProcedureAst>> procs;
    for (auto &proc : context->procedure()) {
        visit(proc);
        procs.push_back(std::move(Procedure));
    }

    Program = std::make_unique<ProgramAst>(std::move(procs));
    return 0;
}

std::any AstBuilder::visitProcedure(SolParser::ProcedureContext *context)
{
    std::string name = context->IDENT()->getText();
    std::vector<std::string> args;

    for (auto &arg : context->args()->arg())
        args.push_back(arg->IDENT()->getText());

    visit(context->returnStatement());

    Procedure =
        std::make_unique<ProcedureAst>(name, args, std::move(ReturnStatement));

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
    auto ident = context->IDENT()->getText();
    Expr = std::make_unique<VariableExprAst>(ident);
    return 0;
}

std::any AstBuilder::visitCallExpr(SolParser::CallExprContext *context)
{
    std::string callee = context->IDENT()->getText();

    std::vector<std::unique_ptr<ExprAst>> args;
    for (auto &arg : context->expression()) {
        visit(arg);
        args.push_back(std::move(Expr));
    }

    Expr = std::make_unique<CallExprAst>(callee, std::move(args));
    return 0;
}

std::any AstBuilder::visitIntExpr(SolParser::IntExprContext *context)
{
    // By the grammar of the language, this should never fail.
    // Unless of course the definition of INT in the grammar is changed.
    auto v = std::stoi(context->INT()->getText());
    Expr = std::make_unique<NumberExprAst>(v);
    return 0;
}

std::any AstBuilder::visitBinopExpr(SolParser::BinopExprContext *context)
{
    std::string op = context->op->getText();

    visit(context->expression(0));
    std::unique_ptr<ExprAst> LHS = std::move(Expr);
    visit(context->expression(1));
    std::unique_ptr<ExprAst> RHS = std::move(Expr);

    Expr = std::make_unique<BinaryExprAst>(op, std::move(LHS), std::move(RHS));
    return 0;
}

} // namespace sol::ast
