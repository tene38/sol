#include "ir/IRGenerator.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/IR/Verifier.h>


namespace sol::ir
{

IRGenerator::IRGenerator(llvm::LLVMContext *TheContext,
                         llvm::IRBuilder<> *TheBuilder, llvm::Module *TheModule)
    : TheContext(TheContext), TheBuilder(TheBuilder), TheModule(TheModule),
      Val(nullptr)
{
}

void IRGenerator::visit(ast::AstNode *ast)
{
    ast->Accept(this);
}

void IRGenerator::visit(ast::ExprAst *ast)
{
    ast->Accept(this);
}

void IRGenerator::visit(ast::NumberExprAst *ast)
{
    Val = llvm::ConstantInt::get(*TheContext,
                                 llvm::APInt(IntSize, ast->GetVal()));
}

void IRGenerator::visit(ast::VariableExprAst *ast)
{
    Val = NamedVariables[ast->GetName()];
}

void IRGenerator::visit(ast::BinaryExprAst *ast)
{
    visit(ast->GetLHS().get());
    llvm::Value *LHS = Val;
    visit(ast->GetRHS().get());
    llvm::Value *RHS = Val;

    std::string Op = ast->GetOp();

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

void IRGenerator::visit(ast::CallExprAst *ast)
{
    llvm::Function *proc = TheModule->getFunction(ast->GetCallee());
    // TODO: this needs error handling:
    // 1. What if the function doesn't exist?
    // 2. What if an incorrect amount of args is passed?
    std::vector<llvm::Value *> args;
    for (auto &arg : ast->GetArgs()) {
        visit(arg.get());
        args.push_back(Val);
    }

    Val = TheBuilder->CreateCall(proc, args, "calltmp");
}

void IRGenerator::visit(ast::ReturnStatementAst *ast)
{
    visit(ast->GetReturnExpression().get());
    Val = TheBuilder->CreateRet(Val);
}

void IRGenerator::visit(ast::ProcedureAst *ast)
{
    // Create a function
    auto &args = ast->GetArgs();
    std::vector<llvm::Type *> Ints(args.size(),
                                   llvm::Type::getInt32Ty(*TheContext));

    llvm::FunctionType *FT = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(*TheContext), Ints, /*varargs=*/false);

    llvm::Function *F = llvm::Function::Create(
        FT, llvm::Function::ExternalLinkage, ast->GetName(), TheModule);

    unsigned i = 0;
    for (auto &Arg : F->args())
        Arg.setName(args[i++]);

    // Add function parameters into the variable map
    NamedVariables.clear();
    for (auto &Arg : F->args())
        NamedVariables[std::string(Arg.getName())] = &Arg;

    // Create a block, set the builder to insert into it
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*TheContext, "entry", F);
    TheBuilder->SetInsertPoint(BB);

    // Recurse into the rest of the function
    visit(ast->GetBody().get());

    // Finish the function
    llvm::verifyFunction(*F);
}

void IRGenerator::visit(ast::ProgramAst *ast)
{
    for (auto &proc : ast->GetProcedures())
        visit(proc.get());
}

llvm::Value *IRGenerator::GetVal()
{
    return Val;
}

std::map<std::string, llvm::Value *> &IRGenerator::GetVariables()
{
    return NamedVariables;
}

} // namespace sol::ir
