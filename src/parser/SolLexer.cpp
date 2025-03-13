
// Generated from Sol.g4 by ANTLR 4.13.2


#include "SolLexer.h"


using namespace antlr4;

using namespace sol::parser;


using namespace antlr4;

namespace {

struct SolLexerStaticData final {
  SolLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SolLexerStaticData(const SolLexerStaticData&) = delete;
  SolLexerStaticData(SolLexerStaticData&&) = delete;
  SolLexerStaticData& operator=(const SolLexerStaticData&) = delete;
  SolLexerStaticData& operator=(SolLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sollexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SolLexerStaticData> sollexerLexerStaticData = nullptr;

void sollexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sollexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(sollexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SolLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "IDENT", "INT", "LF", 
      "BLOCK_COMMENT", "LINE_COMMENT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,20,137,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,
  	1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	1,11,1,12,1,12,1,13,1,13,1,14,1,14,5,14,87,8,14,10,14,12,14,90,9,14,1,
  	15,4,15,93,8,15,11,15,12,15,94,1,16,3,16,98,8,16,1,16,1,16,1,16,1,16,
  	1,17,1,17,1,17,1,17,5,17,108,8,17,10,17,12,17,111,9,17,1,17,1,17,1,17,
  	1,17,1,17,1,18,1,18,1,18,1,18,5,18,122,8,18,10,18,12,18,125,9,18,1,18,
  	1,18,1,18,1,18,1,19,4,19,132,8,19,11,19,12,19,133,1,19,1,19,2,109,123,
  	0,20,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,1,0,4,3,0,65,90,95,95,97,122,
  	4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,142,0,1,1,
  	0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,
  	13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,
  	0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,
  	0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,1,41,1,0,0,0,3,51,1,0,0,0,5,
  	53,1,0,0,0,7,57,1,0,0,0,9,59,1,0,0,0,11,61,1,0,0,0,13,63,1,0,0,0,15,65,
  	1,0,0,0,17,67,1,0,0,0,19,74,1,0,0,0,21,76,1,0,0,0,23,78,1,0,0,0,25,80,
  	1,0,0,0,27,82,1,0,0,0,29,84,1,0,0,0,31,92,1,0,0,0,33,97,1,0,0,0,35,103,
  	1,0,0,0,37,117,1,0,0,0,39,131,1,0,0,0,41,42,5,112,0,0,42,43,5,114,0,0,
  	43,44,5,111,0,0,44,45,5,99,0,0,45,46,5,101,0,0,46,47,5,100,0,0,47,48,
  	5,117,0,0,48,49,5,114,0,0,49,50,5,101,0,0,50,2,1,0,0,0,51,52,5,58,0,0,
  	52,4,1,0,0,0,53,54,5,105,0,0,54,55,5,110,0,0,55,56,5,116,0,0,56,6,1,0,
  	0,0,57,58,5,123,0,0,58,8,1,0,0,0,59,60,5,125,0,0,60,10,1,0,0,0,61,62,
  	5,40,0,0,62,12,1,0,0,0,63,64,5,44,0,0,64,14,1,0,0,0,65,66,5,41,0,0,66,
  	16,1,0,0,0,67,68,5,114,0,0,68,69,5,101,0,0,69,70,5,116,0,0,70,71,5,117,
  	0,0,71,72,5,114,0,0,72,73,5,110,0,0,73,18,1,0,0,0,74,75,5,59,0,0,75,20,
  	1,0,0,0,76,77,5,42,0,0,77,22,1,0,0,0,78,79,5,47,0,0,79,24,1,0,0,0,80,
  	81,5,45,0,0,81,26,1,0,0,0,82,83,5,43,0,0,83,28,1,0,0,0,84,88,7,0,0,0,
  	85,87,7,1,0,0,86,85,1,0,0,0,87,90,1,0,0,0,88,86,1,0,0,0,88,89,1,0,0,0,
  	89,30,1,0,0,0,90,88,1,0,0,0,91,93,7,2,0,0,92,91,1,0,0,0,93,94,1,0,0,0,
  	94,92,1,0,0,0,94,95,1,0,0,0,95,32,1,0,0,0,96,98,5,13,0,0,97,96,1,0,0,
  	0,97,98,1,0,0,0,98,99,1,0,0,0,99,100,5,10,0,0,100,101,1,0,0,0,101,102,
  	6,16,0,0,102,34,1,0,0,0,103,104,5,47,0,0,104,105,5,42,0,0,105,109,1,0,
  	0,0,106,108,9,0,0,0,107,106,1,0,0,0,108,111,1,0,0,0,109,110,1,0,0,0,109,
  	107,1,0,0,0,110,112,1,0,0,0,111,109,1,0,0,0,112,113,5,42,0,0,113,114,
  	5,47,0,0,114,115,1,0,0,0,115,116,6,17,0,0,116,36,1,0,0,0,117,118,5,47,
  	0,0,118,119,5,47,0,0,119,123,1,0,0,0,120,122,9,0,0,0,121,120,1,0,0,0,
  	122,125,1,0,0,0,123,124,1,0,0,0,123,121,1,0,0,0,124,126,1,0,0,0,125,123,
  	1,0,0,0,126,127,3,33,16,0,127,128,1,0,0,0,128,129,6,18,0,0,129,38,1,0,
  	0,0,130,132,7,3,0,0,131,130,1,0,0,0,132,133,1,0,0,0,133,131,1,0,0,0,133,
  	134,1,0,0,0,134,135,1,0,0,0,135,136,6,19,0,0,136,40,1,0,0,0,7,0,88,94,
  	97,109,123,133,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sollexerLexerStaticData = std::move(staticData);
}

}

SolLexer::SolLexer(CharStream *input) : Lexer(input) {
  SolLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *sollexerLexerStaticData->atn, sollexerLexerStaticData->decisionToDFA, sollexerLexerStaticData->sharedContextCache);
}

SolLexer::~SolLexer() {
  delete _interpreter;
}

std::string SolLexer::getGrammarFileName() const {
  return "Sol.g4";
}

const std::vector<std::string>& SolLexer::getRuleNames() const {
  return sollexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SolLexer::getChannelNames() const {
  return sollexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SolLexer::getModeNames() const {
  return sollexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SolLexer::getVocabulary() const {
  return sollexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SolLexer::getSerializedATN() const {
  return sollexerLexerStaticData->serializedATN;
}

const atn::ATN& SolLexer::getATN() const {
  return *sollexerLexerStaticData->atn;
}




void SolLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sollexerLexerInitialize();
#else
  ::antlr4::internal::call_once(sollexerLexerOnceFlag, sollexerLexerInitialize);
#endif
}
