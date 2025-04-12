#include "llvm/IR/Argument.h"
#include <gtest/gtest.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/Constants.h>
#include <llvm/Support/raw_ostream.h>

#include "ast/Ast.hpp"
#include "ast/AstBuilder.hpp"
#include "ir/IrGenerator.hpp"

namespace ast = sol::ast;

class TestIrGenerator : public testing::Test
{
  protected:
    std::unique_ptr<llvm::LLVMContext> Context =
        std::make_unique<llvm::LLVMContext>();
    std::unique_ptr<llvm::IRBuilder<>> Builder =
        std::make_unique<llvm::IRBuilder<>>(*Context);
    std::unique_ptr<llvm::Module> Module =
        std::make_unique<llvm::Module>("test_module", *Context);

    sol::ir::IrGenerator IrGen =
        sol::ir::IrGenerator(Context.get(), Builder.get(), Module.get());
};

TEST_F(TestIrGenerator, VisitNumberAst)
{
    sol::ast::NumberExprAst numberAst(7);

    IrGen.visit(&numberAst);

    llvm::Value *val = IrGen.getVal();
    llvm::ConstantInt *constInt;
    ASSERT_TRUE(constInt = dyn_cast<llvm::ConstantInt>(val));
    EXPECT_EQ(llvm::APInt(32, 7), constInt->getValue());
}

/* TEST_F(TestIRGenerator, VisitVariableAst) */
/* { */
/*     // TODO: create a function first */
/*     sol::ast::VariableExprAst varAst("x"); */
/*     IrGen.visit(&varAst); */
/*     llvm::Value *val = IrGen.getVal(); */
/*     ASSERT_TRUE(val != nullptr); */
/*     llvm::Argument *arg; */
/*     ASSERT_TRUE(arg = static_cast<llvm::Argument *>(val)); */
/*     EXPECT_TRUE(arg->getName() == "x"); */
/* } */

/* TEST_F(TestIrGenerator, VisitBinaryExpressionAst) */
/* { */
/*     auto LHS = std::make_unique<sol::ast::NumberExprAst>(10); */
/*     auto RHS = std::make_unique<sol::ast::NumberExprAst>(20); */
/*     sol::ast::BinaryExprAst BinOp("+", std::move(LHS), std::move(RHS)); */

/*     IrGen.visit(&BinOp); */

/*     llvm::Value *Val = IrGen.getVal(); */
/*     Val->print(llvm::outs()); */
/*     ASSERT_TRUE(isa<llvm::Operator>(Val)); */
/* } */

TEST_F(TestIrGenerator, GeneratesCorrectIr1) {
    // Sol program:
    // procedure main(x: int, y: int): int {
    //      return x + y;
    // }

    const std::string expected = (
        "; ModuleID = 'test_module'\n"
        "source_filename = \"test_module\"\n"
        "\n"
        "define i32 @main(i32 %x, i32 %y) {\n"
        "entry:\n"
        "  %addtmp = add i32 %x, %y\n"
        "  ret i32 %addtmp\n"
        "}\n"
    );

    // Build the AST
    auto X = std::make_unique<ast::VariableExprAst>("x");
    auto Y = std::make_unique<ast::VariableExprAst>("y");
    auto AddExpr = std::make_unique<ast::BinaryExprAst>("+", std::move(X), std::move(Y));
    auto Return = std::make_unique<ast::ReturnStatementAst>(std::move(AddExpr));
    std::vector<std::string> Args = {"x", "y"};
    auto Main = std::make_unique<ast::ProcedureAst>("main", Args, std::move(Return));
    auto Procs = std::vector<std::unique_ptr<ast::ProcedureAst>>();
    Procs.push_back(std::move(Main));
    auto Program = std::make_unique<ast::ProgramAst>(std::move(Procs));

    // Run the generator
    IrGen.visit(Program.get());
    std::string result;
    auto stream = llvm::raw_string_ostream(result);
    Module->print(stream, nullptr);

    // Check if the result matches
    ASSERT_EQ(result, expected);
}
