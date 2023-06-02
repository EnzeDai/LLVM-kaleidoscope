#ifndef __FUNCTION_AST_H__
#define __FUNCTION_AST_H__

#include "ast/PrototypeAST.h"

//----------------------------//
//    Function Definition 
//        函 数 定 义
//----------------------------//

// Class for function definition
class FunctionAST {
    std::unique_ptr<PrototypeAST> Proto;
    std::unique_ptr<ExprAST> Body;

    public:
        FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body) : Proto(std::move(proto)), Body(std::move(body)) {}
        llvm::Function *codegen();
};

#endif