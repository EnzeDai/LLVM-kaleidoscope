#ifndef __VARIABLE_EXPR_AST_H__
#define __VARIABLE_EXPR_AST_H__

#include "ast/ExprAST.h"
#include "logger/logger.h"

//----------------------------//
//    Variable Expression
//       变 量 表 达 式
//----------------------------//

// Class for variable reference, like 'a'
class VariableExprAST : public ExprAST {
    std::string Name;

    public:
        VariableExprAST(const std::string &name) : Name(name) {}
        llvm::Value *codegen() override;
};

#endif