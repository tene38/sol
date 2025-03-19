#include <gtest/gtest.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/Constants.h>
#include "llvm/IR/Argument.h"

#include "ast/Ast.hpp"
#include "ast/AstBuilder.hpp"
#include "ir/IrGenerator.hpp"

class TestIRGenerator : public testing::Test
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

TEST_F(TestIRGenerator, VisitNumberAst)
{
    sol::ast::NumberExprAst numberAst(7);
    IrGen.visit(&numberAst);
    llvm::Value *val = IrGen.getVal();
    llvm::ConstantInt *constInt;
    // TODO: read about static_cast and dynamic_cast.
    ASSERT_TRUE(constInt = static_cast<llvm::ConstantInt *>(val));
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
