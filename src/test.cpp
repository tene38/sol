#include <gtest/gtest.h>
#include <iostream>
#include <llvm/IR/Argument.h>
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

    void MakeFunction(std::vector<std::string> Args,
                      std::map<std::string, llvm::Value *> &Vars);
};

void TestIrGenerator::MakeFunction(std::vector<std::string> Args,
                                   std::map<std::string, llvm::Value *> &Vars)
{
    std::vector<llvm::Type *> Ints(Args.size(),
                                   llvm::Type::getInt32Ty(*Context));

    llvm::FunctionType *FunctionType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(*Context), Ints, /*varargs=*/false);

    llvm::Function *Function = llvm::Function::Create(
        FunctionType, llvm::Function::ExternalLinkage, "func", *Module);

    unsigned i = 0;
    for (auto &Arg : Function->args()) {
        auto Name = Args[i++];
        Arg.setName(Name);
        Vars[std::string(Name)] = &Arg;
    }
}

TEST_F(TestIrGenerator, VisitNumberAst)
{
    sol::ast::NumberExprAst NumberAst(7);

    IrGen.visit(&NumberAst);

    llvm::Value *Val = IrGen.getVal();
    llvm::ConstantInt *ConstInt;
    ASSERT_TRUE(ConstInt = dyn_cast<llvm::ConstantInt>(Val));
    EXPECT_EQ(llvm::APInt(32, 7), ConstInt->getValue());
}

TEST_F(TestIrGenerator, VisitVariableAst)
{
    auto &Vars = IrGen.getVariables();
    MakeFunction({"x"}, Vars);
    sol::ast::VariableExprAst VarAst("x");

    IrGen.visit(&VarAst);

    llvm::Value *Val = IrGen.getVal();
    ASSERT_TRUE(Val != nullptr);

    llvm::Argument *Arg;
    ASSERT_TRUE(Arg = dyn_cast<llvm::Argument>(Val));
    ASSERT_EQ(Arg->getName(), "x");
}

TEST_F(TestIrGenerator, VisitAddition)
{
    auto LHS = std::make_unique<sol::ast::NumberExprAst>(10);
    auto RHS = std::make_unique<sol::ast::VariableExprAst>("x");

    auto &Vars = IrGen.getVariables();

    MakeFunction({"x"}, Vars);

    sol::ast::BinaryExprAst BinOp("+", std::move(LHS), std::move(RHS));

    IrGen.visit(&BinOp);

    llvm::Value *Val = IrGen.getVal();
    ASSERT_TRUE(Val != nullptr);

    llvm::AddOperator *Op;
    ASSERT_TRUE(Op = dyn_cast<llvm::AddOperator>(Val));
    ASSERT_EQ(Op->getNumOperands(), 2);

    auto LHS2 = Op->getOperand(0);
    auto RHS2 = Op->getOperand(1);

    llvm::ConstantInt *Const10;
    ASSERT_TRUE(Const10 = dyn_cast<llvm::ConstantInt>(LHS2));
    EXPECT_EQ(llvm::APInt(32, 10), Const10->getValue());

    llvm::Argument *ArgX;
    ASSERT_TRUE(ArgX = dyn_cast<llvm::Argument>(RHS2));
    EXPECT_EQ(ArgX->getName(), "x");
}

TEST_F(TestIrGenerator, GeneratesCorrectIr1)
{
    // Sol program:
    // procedure main(x: int, y: int): int {
    //      return x + y;
    // }

    const std::string expected =
        ("; ModuleID = 'test_module'\n"
         "source_filename = \"test_module\"\n"
         "\n"
         "define i32 @main(i32 %x, i32 %y) {\n"
         "entry:\n"
         "  %addtmp = add i32 %x, %y\n"
         "  ret i32 %addtmp\n"
         "}\n");

    // Build the AST
    auto X = std::make_unique<ast::VariableExprAst>("x");
    auto Y = std::make_unique<ast::VariableExprAst>("y");
    auto AddExpr =
        std::make_unique<ast::BinaryExprAst>("+", std::move(X), std::move(Y));
    auto Return = std::make_unique<ast::ReturnStatementAst>(std::move(AddExpr));
    std::vector<std::string> Args = {"x", "y"};
    auto Main =
        std::make_unique<ast::ProcedureAst>("main", Args, std::move(Return));
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
