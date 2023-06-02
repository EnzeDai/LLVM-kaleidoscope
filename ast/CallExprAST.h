#ifndef __CALLEXPR_AST_H__
#define __CALLEXPR_AST_H__

#include "llvm/IR/IRBuilder.h"
#include "ast/ExprAST.h"
#include "logger/logger.h"
#include "kaleidoscope/kaleidoscope.h"

//-----------------------------//
//    Func Call Expression 
//     函 数 调 用 表 达 式
//-----------------------------//

// Class for function call expressions
class CallExprAST : public ExprAST {
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> Args;

    public:
        CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args) : Callee(callee), Args(std::move(args)) {}
        llvm::Value *codegen() override;
};

#endif