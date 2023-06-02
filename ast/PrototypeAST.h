#ifndef __PROTOTYPE_AST_H__
#define __PROTOTYPE_AST_H__

#include "llvm/IR/IRBuilder.h"
#include "ast/ExprAST.h"
#include "kaleidoscope/kaleidoscope.h"

//----------------------------//
//    Function Prototype
//        函 数 原 型
//----------------------------//

// Class of a function's prototype, incl. its name and arguments.
class PrototypeAST {
    std::string Name;
    std::vector<std::string> Args;

    public:
        PrototypeAST(const std::string &name, std::vector<std::string> args) : Name(name), Args(std::move(args)) {}

        llvm::Function *codegen();
        const std::string &getName() const { return Name; }
};

#endif