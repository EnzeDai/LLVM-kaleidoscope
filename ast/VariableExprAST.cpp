#include "ast/VariableExprAST.h"

// Assumption: the variable has been emitted somewhere.
llvm::Value *VariableExprAST::codegen() {
    llvm::Value *V = NamedValues[Name];

    if (!V) {
        LogErrorV("Unkown variable name.");
    }

    return V;
}