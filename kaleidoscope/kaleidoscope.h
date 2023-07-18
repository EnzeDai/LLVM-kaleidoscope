#ifndef __KALEIDOSCOPE_H__
#define __KALEIDOSCOPE_H__

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include <map>

// Context owns LLVM core data structures
extern llvm::LLVMContext Context;
// Builder paves the way for generating LLVM instructions
extern llvm::IRBuilder<> Builder;
// Module is an LLVM construct containing functions and global variables
extern std::unique_ptr<llvm::Module> TheModule;
// NamedValues keeps track of which values are defined in the current scope
extern std::map<std::string, llvm::Value *> NamedValues;

#endif