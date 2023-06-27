#include "parser/parser.h"

std::map<char, int> BinopPriority;

// 获取当前处理的 token 的优先级
static int GetTokPriority() {
    if (!isascii(CurToken)) {
        return -1;
    }

    int TokPrior = BinopPriority[CurToken];
    if (TokPrior <= 0) return -1;

    return TokPrior;
}

/*=== BELOW: Function implementation of parser.h file ===*/

// the routine is for tok_number
// It takes the current number value and creates a NumberExprAST node
std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken();
    return std::move(Result);
}

// todo: not understand
// the routine parses expressions in "(" and ")" characters.
std::unique_ptr<ExprAST> ParseParentExpr() {
    getNextToken();

    auto V = ParseExpression();
    if (!V) {
        return nullptr;
    }

    if (CurToken != ')') {
        return LogError("Expect ')'")
    }

    getNextToken();
    return V;
}

// the routine is for tok_identifier(variable)
std::unique_ptr<ExprAST> ParseIdentifierExpr() {
    std::string IdName = IdentifierStr;

    getNextToken();

    if (CurToken != '(') {
        return std::make_unique<VariableExprAST>(IdName);
    }

    getNextToken();
    std::vector<std::unique_ptr<ExprAST>> Args;

    if (CurToken != ')') {
        // todo
    }
}

std::unique_ptr<ExprAST> ParsePrimary() {

}

std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrior, std::unique_ptr<ExprAST> LHS) {

}

std::unique_ptr<ExprAST> ParseExpression() {
    auto LHS = ParsePrimary();

    if (!LHS) {
        return nullptr;
    }

    return ParseBinOpRHS(0, std::move(LHS));
}

std::unique_ptr<PrototypeAST> ParsePrototype() {

}

std::unique_ptr<FunctionAST> ParseDefinition() {
    
}

std::unique_ptr<FunctionAST> ParseTopLevelExpr() {
    
}

std::unique_ptr<PrototypeAST> ParseExtern() {
    
}