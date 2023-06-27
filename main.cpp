// stdlib headers
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <vector>

// LLVM headers
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

// ast headers
#include "ast/BinaryExprAST.h"
#include "ast/CallExprAST.h"
#include "ast/ExprAST.h"
#include "ast/FunctionAST.h"
#include "ast/NumberExprAST.h"
#include "ast/PrototypeAST.h"
#include "ast/VariableExprAST.h"

// kaleidoscope header
#include "kaleidoscope/kaleidoscope.h"

// lexer headers
#include "lexer/lexer.h"
#include "lexer/token.h"

// logger header
#include "logger/logger.h"

// parser header
#include "parser/parser.h"

using namespace llvm;

// ==========================
// ==  Handle Everything   ==
// ==========================

static void HandleDefinition() {

}

static void HandleExtern() {

}

static void HandleTopLevelExpression() {

}

static void MainLoop() {

}

int main() {
    // Set operator priority
    BinopPriority['<'] = 10;
    BinopPriority['+'] = 20;
    BinopPriority['-'] = 20;
    BinopPriority['*'] = 40;

    fprintf(stderr, "READY> ");
    getNextToken();


    return 0;
}