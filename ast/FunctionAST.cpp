#include "ast/FunctionAST.h"

// Generate LLVM code for funciton definitions
llvm::Function *FunctionAST::codegen() {
    llvm::Function *Function = Module->getFunction(Proto->getName());

    // The function's prototype hasn't been generated yet.
    if (!Function) {
        Proto->codegen();
    }

    // Generated failed
    if (!Function) {
        return nullptr;
    }

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(Context, "entry", Function);
    Builder.SetInsertPoint(BB);
    NamedValues.clear(); // [WARN]: Memory leakages may exist.

    for (auto &Arg : Function->args()) {
        NamedValues[Arg.getName().data()] = &Arg;
    }

    if (llvm::Value *RetVal = Body->codegen()) {
        Builder.CreateRet(RetVal);
        verifyFunction(*Function);

        return Function;
    }

    Function->eraseFromParent();
    return nullptr;
}