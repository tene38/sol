
// Generated from Sol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SolParser.h"


namespace sol::parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SolParser.
 */
class  SolVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SolParser.
   */
    virtual std::any visitProgram(SolParser::ProgramContext *context) = 0;

    virtual std::any visitProcedure(SolParser::ProcedureContext *context) = 0;

    virtual std::any visitArgs(SolParser::ArgsContext *context) = 0;

    virtual std::any visitArg(SolParser::ArgContext *context) = 0;

    virtual std::any visitReturn_statement(SolParser::Return_statementContext *context) = 0;

    virtual std::any visitExpression(SolParser::ExpressionContext *context) = 0;

    virtual std::any visitFunc_call(SolParser::Func_callContext *context) = 0;


};

}  // namespace sol::parser
