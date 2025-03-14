#pragma once

#include <string>
#include <vector>
#include <memory>

namespace sol::ast
{

class AstVisitor;

class AstNode
{
  public:
    virtual void Accept(AstVisitor *visitor) = 0;
    virtual ~AstNode() = default;
};

class ExprAst : public AstNode
{
};

class NumberExprAst : public ExprAst
{
    int Val;

  public:
    NumberExprAst(int Val);
    void Accept(AstVisitor *visitor);
};

class VariableExprAst : public ExprAst
{
    std::string Name;

  public:
    VariableExprAst(const std::string &Name);
    void Accept(AstVisitor *visitor);
};

class BinaryExprAst : public ExprAst
{
    std::string Op; // TODO: Should probably be an enum
    std::unique_ptr<ExprAst> LHS, RHS;

  public:
    BinaryExprAst(const std::string &Op, std::unique_ptr<ExprAst> LHS,
                  std::unique_ptr<ExprAst> RHS);
    void Accept(AstVisitor *visitor);
};

class CallExprAst : public ExprAst
{
    std::string Callee; // TODO: this should probably be a ProcedureAst
    std::vector<std::unique_ptr<ExprAst>> Args;

  public:
    CallExprAst(const std::string &Callee,
                std::vector<std::unique_ptr<ExprAst>> Args);
    void Accept(AstVisitor *visitor);
};

class ReturnStatementAst : public AstNode
{
    std::unique_ptr<ExprAst> ReturnExpression;

  public:
    ReturnStatementAst(std::unique_ptr<ExprAst> ReturnExpr);
    void Accept(AstVisitor *visitor);
};

class ProcedureAst : public AstNode
{
    std::string Name;
    std::vector<std::string> Args;
    std::unique_ptr<ReturnStatementAst> Body;

  public:
    ProcedureAst(const std::string &Name, std::vector<std::string> &Args,
                 std::unique_ptr<ReturnStatementAst> Body);
    void Accept(AstVisitor *visitor);
};

class ProgramAst : public AstNode
{
    std::vector<std::unique_ptr<ProcedureAst>> Procedures;

  public:
    ProgramAst(std::vector<std::unique_ptr<ProcedureAst>> Procedures);
    void Accept(AstVisitor *visitor);
};

} // namespace sol::ast
