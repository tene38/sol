
// Generated from Sol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SolParser.h"


namespace sol::parser {

/**
 * This interface defines an abstract listener for a parse tree produced by SolParser.
 */
class  SolListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(SolParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(SolParser::ProgramContext *ctx) = 0;

  virtual void enterProcedure(SolParser::ProcedureContext *ctx) = 0;
  virtual void exitProcedure(SolParser::ProcedureContext *ctx) = 0;

  virtual void enterArgs(SolParser::ArgsContext *ctx) = 0;
  virtual void exitArgs(SolParser::ArgsContext *ctx) = 0;

  virtual void enterArg(SolParser::ArgContext *ctx) = 0;
  virtual void exitArg(SolParser::ArgContext *ctx) = 0;

  virtual void enterReturnStatement(SolParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(SolParser::ReturnStatementContext *ctx) = 0;

  virtual void enterIdentExpr(SolParser::IdentExprContext *ctx) = 0;
  virtual void exitIdentExpr(SolParser::IdentExprContext *ctx) = 0;

  virtual void enterCallExpr(SolParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(SolParser::CallExprContext *ctx) = 0;

  virtual void enterIntExpr(SolParser::IntExprContext *ctx) = 0;
  virtual void exitIntExpr(SolParser::IntExprContext *ctx) = 0;

  virtual void enterBinopExpr(SolParser::BinopExprContext *ctx) = 0;
  virtual void exitBinopExpr(SolParser::BinopExprContext *ctx) = 0;


};

}  // namespace sol::parser
