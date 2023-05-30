#ifndef __BINARY_EXPR_AST_H__
#define __BINARY_EXPR_AST_H__

#include "llvm/IR/IRBuilder.h"
#include "logger/logger.h"
#include "ast/ExprAST.h"

//-----------------------------//
//     Binary Expression 
//       二 元 表 达 式
//     e.g. a + b, a - b
//-----------------------------//

// Class for binary operator, inherited from ExprAST
class BinaryExprAST : public ExprAST {
    char Op;
    std::unique_ptr<ExprAST> LHS, RHS; // Left-Hand Side, Right-Hand Side

    public:
        BinaryExprAST(char op, std::unique_ptr<ExprAST> lhs, std::unique_ptr<ExprAST> rhs) : Op(op), LHS(std::move(lhs)), RHS(std::move(rhs)) {}
        llvm::Value *codegen() override;
};

#endif