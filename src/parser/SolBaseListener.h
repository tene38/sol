
// Generated from Sol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SolListener.h"


namespace sol::parser {

/**
 * This class provides an empty implementation of SolListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SolBaseListener : public SolListener {
public:

  virtual void enterProgram(SolParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(SolParser::ProgramContext * /*ctx*/) override { }

  virtual void enterProcedure(SolParser::ProcedureContext * /*ctx*/) override { }
  virtual void exitProcedure(SolParser::ProcedureContext * /*ctx*/) override { }

  virtual void enterArgs(SolParser::ArgsContext * /*ctx*/) override { }
  virtual void exitArgs(SolParser::ArgsContext * /*ctx*/) override { }

  virtual void enterArg(SolParser::ArgContext * /*ctx*/) override { }
  virtual void exitArg(SolParser::ArgContext * /*ctx*/) override { }

  virtual void enterReturn_statement(SolParser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(SolParser::Return_statementContext * /*ctx*/) override { }

  virtual void enterExpression(SolParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SolParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterFunc_call(SolParser::Func_callContext * /*ctx*/) override { }
  virtual void exitFunc_call(SolParser::Func_callContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace sol::parser
