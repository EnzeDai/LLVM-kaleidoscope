#include "NumberExprAST.h"

// Generate LLVM code for numeric literals
llvm::Value *NumberExprAST::codegen() {
    return llvm::ConstantFP::get(Context, llvm::APFloat(Val));
}