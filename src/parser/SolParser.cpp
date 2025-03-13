
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
      "program", "procedure", "args", "arg", "return_statement", "expression", 
      "func_call"
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
  	4,1,20,90,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	5,0,16,8,0,10,0,12,0,19,9,0,1,1,1,1,1,1,1,1,1,1,3,1,26,8,1,1,1,1,1,1,
  	1,1,1,1,2,1,2,1,2,1,2,5,2,36,8,2,10,2,12,2,39,9,2,3,2,41,8,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,3,5,57,8,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,71,8,5,10,5,12,5,74,9,5,1,6,
  	1,6,1,6,1,6,1,6,5,6,81,8,6,10,6,12,6,84,9,6,3,6,86,8,6,1,6,1,6,1,6,1,
  	17,1,10,7,0,2,4,6,8,10,12,0,0,94,0,17,1,0,0,0,2,20,1,0,0,0,4,31,1,0,0,
  	0,6,44,1,0,0,0,8,48,1,0,0,0,10,56,1,0,0,0,12,75,1,0,0,0,14,16,3,2,1,0,
  	15,14,1,0,0,0,16,19,1,0,0,0,17,18,1,0,0,0,17,15,1,0,0,0,18,1,1,0,0,0,
  	19,17,1,0,0,0,20,21,5,1,0,0,21,22,5,15,0,0,22,25,3,4,2,0,23,24,5,2,0,
  	0,24,26,5,3,0,0,25,23,1,0,0,0,25,26,1,0,0,0,26,27,1,0,0,0,27,28,5,4,0,
  	0,28,29,3,8,4,0,29,30,5,5,0,0,30,3,1,0,0,0,31,40,5,6,0,0,32,37,3,6,3,
  	0,33,34,5,7,0,0,34,36,3,6,3,0,35,33,1,0,0,0,36,39,1,0,0,0,37,35,1,0,0,
  	0,37,38,1,0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,40,32,1,0,0,0,40,41,1,0,0,
  	0,41,42,1,0,0,0,42,43,5,8,0,0,43,5,1,0,0,0,44,45,5,15,0,0,45,46,5,2,0,
  	0,46,47,5,3,0,0,47,7,1,0,0,0,48,49,5,9,0,0,49,50,3,10,5,0,50,51,5,10,
  	0,0,51,9,1,0,0,0,52,53,6,5,-1,0,53,57,5,16,0,0,54,57,5,15,0,0,55,57,3,
  	12,6,0,56,52,1,0,0,0,56,54,1,0,0,0,56,55,1,0,0,0,57,72,1,0,0,0,58,59,
  	10,4,0,0,59,60,5,11,0,0,60,71,3,10,5,5,61,62,10,3,0,0,62,63,5,12,0,0,
  	63,71,3,10,5,4,64,65,10,2,0,0,65,66,5,13,0,0,66,71,3,10,5,3,67,68,10,
  	1,0,0,68,69,5,14,0,0,69,71,3,10,5,2,70,58,1,0,0,0,70,61,1,0,0,0,70,64,
  	1,0,0,0,70,67,1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,1,0,0,0,73,11,
  	1,0,0,0,74,72,1,0,0,0,75,76,5,15,0,0,76,85,5,6,0,0,77,82,3,10,5,0,78,
  	79,5,7,0,0,79,81,3,10,5,0,80,78,1,0,0,0,81,84,1,0,0,0,82,80,1,0,0,0,82,
  	83,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,85,77,1,0,0,0,85,86,1,0,0,0,86,
  	87,1,0,0,0,87,88,5,8,0,0,88,13,1,0,0,0,9,17,25,37,40,56,70,72,82,85
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
    setState(17);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(14);
        procedure(); 
      }
      setState(19);
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

SolParser::Return_statementContext* SolParser::ProcedureContext::return_statement() {
  return getRuleContext<SolParser::Return_statementContext>(0);
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
    setState(20);
    match(SolParser::T__0);
    setState(21);
    match(SolParser::IDENT);
    setState(22);
    args();
    setState(25);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolParser::T__1) {
      setState(23);
      match(SolParser::T__1);
      setState(24);
      match(SolParser::T__2);
    }
    setState(27);
    match(SolParser::T__3);
    setState(28);
    return_statement();
    setState(29);
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
    setState(31);
    match(SolParser::T__5);
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolParser::IDENT) {
      setState(32);
      arg();
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SolParser::T__6) {
        setState(33);
        match(SolParser::T__6);
        setState(34);
        arg();
        setState(39);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(42);
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
    setState(44);
    match(SolParser::IDENT);
    setState(45);
    match(SolParser::T__1);
    setState(46);
    match(SolParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

SolParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolParser::ExpressionContext* SolParser::Return_statementContext::expression() {
  return getRuleContext<SolParser::ExpressionContext>(0);
}


size_t SolParser::Return_statementContext::getRuleIndex() const {
  return SolParser::RuleReturn_statement;
}

void SolParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void SolParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}


std::any SolParser::Return_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitReturn_statement(this);
  else
    return visitor->visitChildren(this);
}

SolParser::Return_statementContext* SolParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 8, SolParser::RuleReturn_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(SolParser::T__8);
    setState(49);
    expression(0);
    setState(50);
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

tree::TerminalNode* SolParser::ExpressionContext::INT() {
  return getToken(SolParser::INT, 0);
}

tree::TerminalNode* SolParser::ExpressionContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}

SolParser::Func_callContext* SolParser::ExpressionContext::func_call() {
  return getRuleContext<SolParser::Func_callContext>(0);
}

std::vector<SolParser::ExpressionContext *> SolParser::ExpressionContext::expression() {
  return getRuleContexts<SolParser::ExpressionContext>();
}

SolParser::ExpressionContext* SolParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<SolParser::ExpressionContext>(i);
}


size_t SolParser::ExpressionContext::getRuleIndex() const {
  return SolParser::RuleExpression;
}

void SolParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SolParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any SolParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
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
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(53);
      match(SolParser::INT);
      break;
    }

    case 2: {
      setState(54);
      match(SolParser::IDENT);
      break;
    }

    case 3: {
      setState(55);
      func_call();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(72);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(70);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(58);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(59);
          match(SolParser::T__10);
          setState(60);
          expression(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(61);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(62);
          match(SolParser::T__11);
          setState(63);
          expression(4);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(64);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(65);
          match(SolParser::T__12);
          setState(66);
          expression(3);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(67);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(68);
          match(SolParser::T__13);
          setState(69);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(74);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

SolParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolParser::Func_callContext::IDENT() {
  return getToken(SolParser::IDENT, 0);
}

std::vector<SolParser::ExpressionContext *> SolParser::Func_callContext::expression() {
  return getRuleContexts<SolParser::ExpressionContext>();
}

SolParser::ExpressionContext* SolParser::Func_callContext::expression(size_t i) {
  return getRuleContext<SolParser::ExpressionContext>(i);
}


size_t SolParser::Func_callContext::getRuleIndex() const {
  return SolParser::RuleFunc_call;
}

void SolParser::Func_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_call(this);
}

void SolParser::Func_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_call(this);
}


std::any SolParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

SolParser::Func_callContext* SolParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 12, SolParser::RuleFunc_call);
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
    setState(75);
    match(SolParser::IDENT);
    setState(76);
    match(SolParser::T__5);
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolParser::IDENT

    || _la == SolParser::INT) {
      setState(77);
      expression(0);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SolParser::T__6) {
        setState(78);
        match(SolParser::T__6);
        setState(79);
        expression(0);
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(87);
    match(SolParser::T__7);
   
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
