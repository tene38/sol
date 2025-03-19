#pragma once

#include <map>
#include <memory>
#include <string>

#include "llvm/ADT/APInt.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "ast/Ast.hpp"
#include "ast/AstVisitor.hpp"

namespace sol::ir
{

class IrGenerator : public ast::AstVisitor
{
    const int INT_SIZE = 32; // bits
    llvm::LLVMContext *TheContext;
    llvm::IRBuilder<> *TheBuilder;
    llvm::Module *TheModule;

    std::map<std::string, llvm::Value *> NamedVariables;
    llvm::Value *Val;

  public:
    IrGenerator(llvm::LLVMContext *TheContext, llvm::IRBuilder<> *TheBuilder,
                llvm::Module *TheModule);

    void visit(ast::AstNode *Ast) override;
    void visit(ast::ExprAst *Ast) override;
    void visit(ast::NumberExprAst *Ast) override;
    void visit(ast::VariableExprAst *Ast) override;
    void visit(ast::BinaryExprAst *Ast) override;
    void visit(ast::CallExprAst *Ast) override;
    void visit(ast::ReturnStatementAst *Ast) override;
    void visit(ast::ProcedureAst *Ast) override;
    void visit(ast::ProgramAst *Ast) override;

    llvm::Value *getVal();
    std::map<std::string, llvm::Value *> &getVariables();
};

} // namespace sol::ir
