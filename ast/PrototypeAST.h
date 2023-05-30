#ifndef __PROTOTYPE_AST_H__
#define __PROTOTYPE_AST_H__

#include "llvm/IR/IRBuilder.h"
#include "ast/ExprAST.h"
#include "kaleidoscope/kaleidoscope.h"

class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;

    public:
        PrototypeAST() {}

};

#endif