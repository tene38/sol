cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 23)

project(Sol C CXX)

find_package(antlr4-runtime REQUIRED)
find_package(LLVM REQUIRED CONFIG)

add_executable(solc)

target_sources(solc PRIVATE
    src/parser/SolLexer.cpp
    src/parser/SolParser.cpp
    src/parser/SolBaseListener.cpp
    src/parser/SolBaseVisitor.cpp
    src/parser/SolListener.cpp
    src/parser/SolVisitor.cpp
    src/ast/Ast.cpp
    src/ast/AstBuilder.cpp
    src/ast/AstPrinter.cpp
    src/ir/IRGenerator.cpp
    src/driver.cpp
)

target_include_directories(solc PRIVATE 
    ${LLVM_INCLUDE_DIRS}
    src
)

# TODO: make this work with packages from Conan. This makefile isn't portable in
# this state.

# If the build fails while linking, remove `USE_SHARED` from the following call:
llvm_config(solc USE_SHARED core)

target_link_libraries(solc PRIVATE
    antlr4_static
)
target_compile_definitions(solc PRIVATE
    ${LLVM_DEFINITIONS_LIST}
)
