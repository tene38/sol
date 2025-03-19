cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 23)

project(Sol C CXX)


# ====================
# Dependencies
# ====================
find_package(antlr4-runtime REQUIRED)
find_package(LLVM REQUIRED CONFIG)
find_package(GTest)
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)


# ====================
# The `solc` compiler
# ====================
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
    src/ir/IrGenerator.cpp
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


# ====================
# Unit tests
# ====================
enable_testing()

# TODO: should the project be divided into static libraries in order to ease
# testing?
add_executable(tests)
target_sources(tests PRIVATE
    src/parser/SolLexer.cpp
    src/parser/SolParser.cpp
    src/parser/SolBaseListener.cpp
    src/parser/SolBaseVisitor.cpp
    src/parser/SolListener.cpp
    src/parser/SolVisitor.cpp
    src/ast/Ast.cpp
    src/ast/AstBuilder.cpp
    src/ast/AstPrinter.cpp
    src/ir/IrGenerator.cpp
    src/test.cpp
)

target_include_directories(tests PRIVATE 
    ${LLVM_INCLUDE_DIRS}
    src
)

llvm_config(tests USE_SHARED core)
target_link_libraries(tests PRIVATE
    GTest::gtest_main
    antlr4_static
)

include(GoogleTest)
gtest_discover_tests(tests)
