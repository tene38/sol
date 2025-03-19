#include "llvm/IR/Constants.h"
#include "llvm/IR/Verifier.h"

#include "ir/IrGenerator.hpp"

namespace sol::ir
{

IrGenerator::IrGenerator(llvm::LLVMContext *TheContext,
                         llvm::IRBuilder<> *TheBuilder, llvm::Module *TheModule)
    : TheContext(TheContext), TheBuilder(TheBuilder), TheModule(TheModule),
      Val(nullptr)
{
}

void IrGenerator::visit(ast::AstNode *Ast)
{
    Ast->accept(this);
}

void IrGenerator::visit(ast::ExprAst *Ast)
{
    Ast->accept(this);
}

void IrGenerator::visit(ast::NumberExprAst *Ast)
{
    Val = llvm::ConstantInt::get(*TheContext,
                                 llvm::APInt(INT_SIZE, Ast->getVal()));
}

void IrGenerator::visit(ast::VariableExprAst *Ast)
{
    Val = NamedVariables[Ast->getName()];
}

void IrGenerator::visit(ast::BinaryExprAst *Ast)
{
    visit(Ast->getLHS().get());
    llvm::Value *LHS = Val;
    visit(Ast->getRHS().get());
    llvm::Value *RHS = Val;

    std::string Op = Ast->getOp();

    if (Op == "+") {
        Val = TheBuilder->CreateAdd(LHS, RHS, "addtmp");
    } else if (Op == "-") {
        Val = TheBuilder->CreateSub(LHS, RHS, "subtmp");
    } else if (Op == "/") {
        Val = TheBuilder->CreateUDiv(LHS, RHS, "divtmp");
    } else if (Op == "*") {
        Val = TheBuilder->CreateMul(LHS, RHS, "multmp");
    }
}

void IrGenerator::visit(ast::CallExprAst *Ast)
{
    llvm::Function *Proc = TheModule->getFunction(Ast->getCallee());
    // TODO: this needs error handling:
    // 1. What if the function doesn't exist?
    // 2. What if an incorrect amount of args is passed?
    std::vector<llvm::Value *> Args;
    for (auto &Arg : Ast->getArgs()) {
        visit(Arg.get());
        Args.push_back(Val);
    }

    Val = TheBuilder->CreateCall(Proc, Args, "calltmp");
}

void IrGenerator::visit(ast::ReturnStatementAst *Ast)
{
    visit(Ast->getReturnExpression().get());
    Val = TheBuilder->CreateRet(Val);
}

void IrGenerator::visit(ast::ProcedureAst *Ast)
{
    // Create a function
    auto &Args = Ast->getArgs();
    std::vector<llvm::Type *> Ints(Args.size(),
                                   llvm::Type::getInt32Ty(*TheContext));

    llvm::FunctionType *FunctionType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(*TheContext), Ints, /*varargs=*/false);

    llvm::Function *Function =
        llvm::Function::Create(FunctionType, llvm::Function::ExternalLinkage,
                               Ast->getName(), TheModule);

    unsigned i = 0;
    for (auto &Arg : Function->args())
        Arg.setName(Args[i++]);

    // Add function parameters into the variable map
    NamedVariables.clear();
    for (auto &Arg : Function->args())
        NamedVariables[std::string(Arg.getName())] = &Arg;

    // Create a block, set the builder to insert into it
    llvm::BasicBlock *FunctionBody = llvm::BasicBlock::Create(*TheContext, "entry", Function);
    TheBuilder->SetInsertPoint(FunctionBody);

    // Recurse into the rest of the function
    visit(Ast->getBody().get());

    // Finish the function
    llvm::verifyFunction(*Function);
}

void IrGenerator::visit(ast::ProgramAst *Ast)
{
    for (auto &Proc : Ast->getProcedures())
        visit(Proc.get());
}

llvm::Value *IrGenerator::getVal()
{
    return Val;
}

std::map<std::string, llvm::Value *> &IrGenerator::getVariables()
{
    return NamedVariables;
}

} // namespace sol::ir
