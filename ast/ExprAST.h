#ifndef __EXPR_AST_H__
#define __EXPR_AST_H__

#include "llvm/IR/BasicBlock.h"

//---------------------------------------//
// Abstract Syntax Tree (aka Parse Tree)
//    抽 象 语 法 树      (亦 称 解 析 树)
//---------------------------------------//

// Base class of all expression nodes.
class ExprAST {
public:
    virtual ~ExprAST() {}
    virtual llvm::Value *codegen() = 0;
};

#endif