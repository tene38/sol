#pragma once

#include <memory>
#include <string>
#include <map>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/ADT/APInt.h"

#include "ast/Ast.hpp"
#include "ast/AstVisitor.hpp"

namespace sol::ir
{

class IRGenerator : public ast::AstVisitor
{
    const int IntSize = 32; // bits
    llvm::LLVMContext *TheContext;
    llvm::IRBuilder<> *TheBuilder;
    llvm::Module *TheModule;

    std::map<std::string, llvm::Value *> NamedVariables;
    llvm::Value *Val;

  public:
    IRGenerator(llvm::LLVMContext *TheContext, llvm::IRBuilder<> *TheBuilder,
                llvm::Module *TheModule);

    void visit(ast::AstNode *ast) override;
    void visit(ast::ExprAst *ast) override;
    void visit(ast::NumberExprAst *ast) override;
    void visit(ast::VariableExprAst *ast) override;
    void visit(ast::BinaryExprAst *ast) override;
    void visit(ast::CallExprAst *ast) override;
    void visit(ast::ReturnStatementAst *ast) override;
    void visit(ast::ProcedureAst *ast) override;
    void visit(ast::ProgramAst *ast) override;
};

} // namespace sol::ir
