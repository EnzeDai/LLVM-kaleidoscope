#include "ast/CallExprAST.h"

// Generate LLVM code for func call expressions
llvm::Value *CallExprAST::codegen() {
    llvm::Function *CalleeFunc = Module->getFunction(Callee);

    if (!CalleeFunc) {
        return LogErrorV("Unknown function reference.");
    }

    if (CalleeFunc->arg_size() != Args.size()) {
        return LogErrorV("Incorrect # arguments.");
    }

    std::vector<llvm::Value *> ArgsV;
    for (unsigned i = 0; i < Args.size(); i++) {
        ArgsV.push_back(Args[i]->codegen());
        
        // if the argument is null
        if (!ArgsV.back()) {
            return nullptr;
        }
    }

    return Builder.CreateCall(CalleeFunc, ArgsV, "calltmp");
}
