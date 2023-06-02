#include "ast/PrototypeAST.h"

// Generate LLVM code for external function calls
llvm::Function *PrototypeAST::codegen() {
    // Args: all func's args are llvm Double type
    std::vector<llvm::Type *> Doubles(Args.size(), llvm::Type::getDoubleTy(Context));

    // FuncType: Func's return Type is double, Args are Doubles and non-variable
    llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getDoubleTy(Context), Doubles, false);
    
    // Func: create LLVM func
    llvm::Function *F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, Name, Module.get());

    // Args is the params passed in
    unsigned Idx = 0;
    for (auto &Arg : F->args()) {
        Arg.setName(Args[Idx++]);
    }

    return F;
}