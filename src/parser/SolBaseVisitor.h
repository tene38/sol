
// Generated from Sol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SolVisitor.h"


namespace sol::parser {

/**
 * This class provides an empty implementation of SolVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SolBaseVisitor : public SolVisitor {
public:

  virtual std::any visitProgram(SolParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedure(SolParser::ProcedureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgs(SolParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArg(SolParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(SolParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentExpr(SolParser::IdentExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpr(SolParser::CallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntExpr(SolParser::IntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinopExpr(SolParser::BinopExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace sol::parser
