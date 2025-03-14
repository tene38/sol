
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

    virtual std::any visitReturnStatement(SolParser::ReturnStatementContext *context) = 0;

    virtual std::any visitIdentExpr(SolParser::IdentExprContext *context) = 0;

    virtual std::any visitCallExpr(SolParser::CallExprContext *context) = 0;

    virtual std::any visitIntExpr(SolParser::IntExprContext *context) = 0;

    virtual std::any visitBinopExpr(SolParser::BinopExprContext *context) = 0;


};

}  // namespace sol::parser
