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
    virtual void accept(AstVisitor *Visitor) = 0;
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
    int getVal();
    void accept(AstVisitor *Visitor);
};

class VariableExprAst : public ExprAst
{
    std::string Name;

  public:
    VariableExprAst(const std::string &Name);
    std::string getName();
    void accept(AstVisitor *Visitor);
};

class BinaryExprAst : public ExprAst
{
    std::string Op; // TODO: Should probably be an enum
    std::unique_ptr<ExprAst> LHS, RHS;

  public:
    BinaryExprAst(const std::string &Op, std::unique_ptr<ExprAst> LHS,
                  std::unique_ptr<ExprAst> RHS);
    std::string getOp();
    std::unique_ptr<ExprAst> &getLHS();
    std::unique_ptr<ExprAst> &getRHS();
    void accept(AstVisitor *Visitor);
};

class CallExprAst : public ExprAst
{
    std::string Callee; // TODO: this should probably be a ProcedureAst
    std::vector<std::unique_ptr<ExprAst>> Args;

  public:
    CallExprAst(const std::string &Callee,
                std::vector<std::unique_ptr<ExprAst>> Args);
    std::string getCallee();
    std::vector<std::unique_ptr<ExprAst>> &getArgs();
    void accept(AstVisitor *Visitor);
};

class ReturnStatementAst : public AstNode
{
    std::unique_ptr<ExprAst> ReturnExpression;

  public:
    ReturnStatementAst(std::unique_ptr<ExprAst> ReturnExpr);
    std::unique_ptr<ExprAst> &getReturnExpression();
    void accept(AstVisitor *Visitor);
};

class ProcedureAst : public AstNode
{
    std::string Name;
    std::vector<std::string> Args;
    std::unique_ptr<ReturnStatementAst> Body;

  public:
    ProcedureAst(const std::string &Name, std::vector<std::string> &Args,
                 std::unique_ptr<ReturnStatementAst> Body);
    std::string getName();
    std::vector<std::string> &getArgs();
    std::unique_ptr<ReturnStatementAst> &getBody();
    void accept(AstVisitor *Visitor);
};

class ProgramAst : public AstNode
{
    std::vector<std::unique_ptr<ProcedureAst>> Procedures;

  public:
    ProgramAst(std::vector<std::unique_ptr<ProcedureAst>> Procedures);
    std::vector<std::unique_ptr<ProcedureAst>> &getProcedures();
    void accept(AstVisitor *Visitor);
};

} // namespace sol::ast
