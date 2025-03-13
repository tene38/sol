
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

  virtual std::any visitReturn_statement(SolParser::Return_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(SolParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_call(SolParser::Func_callContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace sol::parser
