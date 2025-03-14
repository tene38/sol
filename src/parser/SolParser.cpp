
// Generated from Sol.g4 by ANTLR 4.13.2


#include "SolListener.h"
#include "SolVisitor.h"

#include "SolParser.h"


using namespace antlrcpp;
using namespace sol::parser;

using namespace antlr4;

namespace {

struct SolParserStaticData final {
  SolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SolParserStaticData(const SolParserStaticData&) = delete;
  SolParserStaticData(SolParserStaticData&&) = delete;
  SolParserStaticData& operator=(const SolParserStaticData&) = delete;
  SolParserStaticData& operator=(SolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag solParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SolParserStaticData> solParserStaticData = nullptr;

void solParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (solParserStaticData != nullptr) {
    return;
  }
#else
  assert(solParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SolParserStaticData>(
    std::vector<std::string>{
      "program", "procedure", "args", "arg", "returnStatement", "expression"
    },
    std::vector<std::string>{
      "", "'procedure'", "':'", "'int'", "'{'", "'}'", "'('", "','", "')'", 
      "'return'", "';'", "'*'", "'/'", "'-'", "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "IDENT", 
      "INT", "LF", "BLOCK_COMMENT", "LINE_COMMENT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,20,86,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,5,0,14,
  	8,0,10,0,12,0,17,9,0,1,1,1,1,1,1,1,1,1,1,3,1,24,8,1,1,1,1,1,1,1,1,1,1,
  	2,1,2,1,2,1,2,5,2,34,8,2,10,2,12,2,37,9,2,3,2,39,8,2,1,2,1,2,1,3,1,3,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,59,8,5,10,
  	5,12,5,62,9,5,3,5,64,8,5,1,5,3,5,67,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,5,5,81,8,5,10,5,12,5,84,9,5,1,5,1,15,1,10,6,0,2,4,6,
  	8,10,0,0,91,0,15,1,0,0,0,2,18,1,0,0,0,4,29,1,0,0,0,6,42,1,0,0,0,8,46,
  	1,0,0,0,10,66,1,0,0,0,12,14,3,2,1,0,13,12,1,0,0,0,14,17,1,0,0,0,15,16,
  	1,0,0,0,15,13,1,0,0,0,16,1,1,0,0,0,17,15,1,0,0,0,18,19,5,1,0,0,19,20,
  	5,15,0,0,20,23,3,4,2,0,21,22,5,2,0,0,22,24,5,3,0,0,23,21,1,0,0,0,23,24,
  	1,0,0,0,24,25,1,0,0,0,25,26,5,4,0,0,26,27,3,8,4,0,27,28,5,5,0,0,28,3,
  	1,0,0,0,29,38,5,6,0,0,30,35,3,6,3,0,31,32,5,7,0,0,32,34,3,6,3,0,33,31,
  	1,0,0,0,34,37,1,0,0,0,35,33,1,0,0,0,35,36,1,0,0,0,36,39,1,0,0,0,37,35,
  	1,0,0,0,38,30,1,0,0,0,38,39,1,0,0,0,39,40,1,0,0,0,40,41,5,8,0,0,41,5,
  	1,0,0,0,42,43,5,15,0,0,43,44,5,2,0,0,44,45,5,3,0,0,45,7,1,0,0,0,46,47,
  	5,9,0,0,47,48,3,10,5,0,48,49,5,10,0,0,49,9,1,0,0,0,50,51,6,5,-1,0,51,
  	67,5,16,0,0,52,67,5,15,0,0,53,54,5,15,0,0,54,63,5,6,0,0,55,60,3,10,5,
  	0,56,57,5,7,0,0,57,59,3,10,5,0,58,56,1,0,0,0,59,62,1,0,0,0,60,58,1,0,
  	0,0,60,61,1,0,0,0,61,64,1,0,0,0,62,60,1,0,0,0,63,55,1,0,0,0,63,64,1,0,
  	0,0,64,65,1,0,0,0,65,67,5,8,0,0,66,50,1,0,0,0,66,52,1,0,0,0,66,53,1,0,
  	0,0,67,82,1,0,0,0,68,69,10,4,0,0,69,70,5,11,0,0,70,81,3,10,5,5,71,72,
  	10,3,0,0,72,73,5,12,0,0,73,81,3,10,5,4,74,75,10,2,0,0,75,76,5,13,0,0,
  	76,81,3,10,5,3,77,78,10,1,0,0,78,79,5,14,0,0,79,81,3,10,5,2,80,68,1,0,
  	0,0,80,71,1,0,0,0,80,74,1,0,0,0,80,77,1,0,0,0,81,84,1,0,0,0,82,80,1,0,
  	0,0,82,83,1,0,0,0,83,11,1,0,0,0,84,82,1,0,0,0,9,15,23,35,38,60,63,66,
  	80,82
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  solParserStaticData = std::move(staticData);
}

}

SolParser::SolParser(TokenStream *input) : SolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SolParser::SolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *solParserStaticData->atn, solParserStaticData->decisionToDFA, solParserStaticData->sharedContextCache, options);
}

SolParser::~SolParser() {
  delete _interpreter;
}

const atn::ATN& SolParser::getATN() const {
  return *solParserStaticData->atn;
}

std::string SolParser::getGrammarFileName() const {
  return "Sol.g4";
}

const std::vector<std::string>& SolParser::getRuleNames() const {
  return solParserStaticData->ruleNames;
}

const dfa::Vocabulary& SolParser::getVocabulary() const {
  return solParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SolParser::getSerializedATN() const {
  return solParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

SolParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SolParser::ProcedureContext *> SolParser::ProgramContext::procedure() {
  return getRuleContexts<SolParser::ProcedureContext>();
}

SolParser::ProcedureContext* SolParser::ProgramContext::procedure(size_t i) {
  return getRuleContext<SolParser::ProcedureContext>(i);
}


size_t SolParser::ProgramContext::getRuleIndex() const {
  return SolParser::RuleProgram;
}

void SolParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void SolParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any SolParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ProgramContext* SolParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SolParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(15);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(12);
        procedure(); 
      }
      setState(17);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureContext ------------------------------------------------------------------

SolParser::ProcedureContext::ProcedureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolParser::ProcedureContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}

SolParser::ArgsContext* SolParser::ProcedureContext::args() {
  return getRuleContext<SolParser::ArgsContext>(0);
}

SolParser::ReturnStatementContext* SolParser::ProcedureContext::returnStatement() {
  return getRuleContext<SolParser::ReturnStatementContext>(0);
}


size_t SolParser::ProcedureContext::getRuleIndex() const {
  return SolParser::RuleProcedure;
}

void SolParser::ProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure(this);
}

void SolParser::ProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure(this);
}


std::any SolParser::ProcedureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitProcedure(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ProcedureContext* SolParser::procedure() {
  ProcedureContext *_localctx = _tracker.createInstance<ProcedureContext>(_ctx, getState());
  enterRule(_localctx, 2, SolParser::RuleProcedure);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    match(SolParser::T__0);
    setState(19);
    match(SolParser::IDENT);
    setState(20);
    args();
    setState(23);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolParser::T__1) {
      setState(21);
      match(SolParser::T__1);
      setState(22);
      match(SolParser::T__2);
    }
    setState(25);
    match(SolParser::T__3);
    setState(26);
    returnStatement();
    setState(27);
    match(SolParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

SolParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SolParser::ArgContext *> SolParser::ArgsContext::arg() {
  return getRuleContexts<SolParser::ArgContext>();
}

SolParser::ArgContext* SolParser::ArgsContext::arg(size_t i) {
  return getRuleContext<SolParser::ArgContext>(i);
}


size_t SolParser::ArgsContext::getRuleIndex() const {
  return SolParser::RuleArgs;
}

void SolParser::ArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgs(this);
}

void SolParser::ArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgs(this);
}


std::any SolParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ArgsContext* SolParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 4, SolParser::RuleArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(SolParser::T__5);
    setState(38);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolParser::IDENT) {
      setState(30);
      arg();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SolParser::T__6) {
        setState(31);
        match(SolParser::T__6);
        setState(32);
        arg();
        setState(37);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(40);
    match(SolParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

SolParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolParser::ArgContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}


size_t SolParser::ArgContext::getRuleIndex() const {
  return SolParser::RuleArg;
}

void SolParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void SolParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}


std::any SolParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ArgContext* SolParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 6, SolParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(SolParser::IDENT);
    setState(43);
    match(SolParser::T__1);
    setState(44);
    match(SolParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

SolParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolParser::ExpressionContext* SolParser::ReturnStatementContext::expression() {
  return getRuleContext<SolParser::ExpressionContext>(0);
}


size_t SolParser::ReturnStatementContext::getRuleIndex() const {
  return SolParser::RuleReturnStatement;
}

void SolParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void SolParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any SolParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ReturnStatementContext* SolParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, SolParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(SolParser::T__8);
    setState(47);
    expression(0);
    setState(48);
    match(SolParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SolParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SolParser::ExpressionContext::getRuleIndex() const {
  return SolParser::RuleExpression;
}

void SolParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentExprContext ------------------------------------------------------------------

tree::TerminalNode* SolParser::IdentExprContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}

SolParser::IdentExprContext::IdentExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void SolParser::IdentExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentExpr(this);
}
void SolParser::IdentExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentExpr(this);
}

std::any SolParser::IdentExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitIdentExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExprContext ------------------------------------------------------------------

tree::TerminalNode* SolParser::CallExprContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}

std::vector<SolParser::ExpressionContext *> SolParser::CallExprContext::expression() {
  return getRuleContexts<SolParser::ExpressionContext>();
}

SolParser::ExpressionContext* SolParser::CallExprContext::expression(size_t i) {
  return getRuleContext<SolParser::ExpressionContext>(i);
}

SolParser::CallExprContext::CallExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void SolParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}
void SolParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}

std::any SolParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntExprContext ------------------------------------------------------------------

tree::TerminalNode* SolParser::IntExprContext::INT() {
  return getToken(SolParser::INT, 0);
}

SolParser::IntExprContext::IntExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void SolParser::IntExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntExpr(this);
}
void SolParser::IntExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntExpr(this);
}

std::any SolParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinopExprContext ------------------------------------------------------------------

std::vector<SolParser::ExpressionContext *> SolParser::BinopExprContext::expression() {
  return getRuleContexts<SolParser::ExpressionContext>();
}

SolParser::ExpressionContext* SolParser::BinopExprContext::expression(size_t i) {
  return getRuleContext<SolParser::ExpressionContext>(i);
}

SolParser::BinopExprContext::BinopExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void SolParser::BinopExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinopExpr(this);
}
void SolParser::BinopExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinopExpr(this);
}

std::any SolParser::BinopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitBinopExpr(this);
  else
    return visitor->visitChildren(this);
}

SolParser::ExpressionContext* SolParser::expression() {
   return expression(0);
}

SolParser::ExpressionContext* SolParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SolParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  SolParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, SolParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<IntExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(51);
      match(SolParser::INT);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdentExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(52);
      match(SolParser::IDENT);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(53);
      match(SolParser::IDENT);
      setState(54);
      match(SolParser::T__5);
      setState(63);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SolParser::IDENT

      || _la == SolParser::INT) {
        setState(55);
        expression(0);
        setState(60);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SolParser::T__6) {
          setState(56);
          match(SolParser::T__6);
          setState(57);
          expression(0);
          setState(62);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(65);
      match(SolParser::T__7);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(82);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(80);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(68);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(69);
          antlrcpp::downCast<BinopExprContext *>(_localctx)->op = match(SolParser::T__10);
          setState(70);
          expression(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(71);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(72);
          antlrcpp::downCast<BinopExprContext *>(_localctx)->op = match(SolParser::T__11);
          setState(73);
          expression(4);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(74);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(75);
          antlrcpp::downCast<BinopExprContext *>(_localctx)->op = match(SolParser::T__12);
          setState(76);
          expression(3);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinopExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(77);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(78);
          antlrcpp::downCast<BinopExprContext *>(_localctx)->op = match(SolParser::T__13);
          setState(79);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(84);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool SolParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SolParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void SolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  solParserInitialize();
#else
  ::antlr4::internal::call_once(solParserOnceFlag, solParserInitialize);
#endif
}
