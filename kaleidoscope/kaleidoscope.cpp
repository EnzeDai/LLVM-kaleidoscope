#include "kaleidoscope.h"

llvm::LLVMContext Context;

llvm::IRBuilder<> Builder(Context);

std::unique_ptr<llvm::Module> Module;

std::map<std::string, llvm::Value *> NamedValues;