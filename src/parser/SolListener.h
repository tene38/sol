
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

  virtual void enterReturn_statement(SolParser::Return_statementContext *ctx) = 0;
  virtual void exitReturn_statement(SolParser::Return_statementContext *ctx) = 0;

  virtual void enterExpression(SolParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SolParser::ExpressionContext *ctx) = 0;

  virtual void enterFunc_call(SolParser::Func_callContext *ctx) = 0;
  virtual void exitFunc_call(SolParser::Func_callContext *ctx) = 0;


};

}  // namespace sol::parser
