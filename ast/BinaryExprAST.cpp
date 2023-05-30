#include "ast/BinaryExprAST.h"
#include "kaleidoscope/kaleidoscope.h"

// Generate LLVM code for binary expressions
llvm::Value *BinaryExprAST::codegen() {
    llvm::Value *L = LHS->codegen();
    llvm::Value *R = RHS->codegen();

    if (!L || !R) {
        return nullptr;
    }

    // F - Float, U - Unsigned, LT - Less Than
    switch (Op) {
        case '+':
            return Builder.CreateFAdd(L, R, "addtmp");
        case '-':
            return Builder.CreateFSub(L, R, "subtmp");
        case '*':
            return Builder.CreateFMul(L, R, "multmp");
        case '<':
            // Compare results
            L = Builder.CreateFCmpULT(L, R, "cmptmp");
            // Convert unsigned int to double type
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(Context), "booltmp");
        default:
            return LogErrorV("Invalid Binary Operator");
    }
}