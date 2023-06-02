#ifndef __NUMBER_EXPR_AST_H__
#define __NUMBER_EXPR_AST_H__

#include "ast/ExprAST.h"
#include "kaleidoscope/kaleidoscope.h"

//--------------------------//
//    Number Expression
//      常 量 表 达 式
//--------------------------//

// Class for numeric literals, such as '1.0'
class NumberExprAST : public ExprAST {
    double Val;

    public:
        NumberExprAST(double val) : Val(val) {}
        llvm::Value *codegen() override;
};

#endif