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

/* === BELOW: Function implementation of parser.h file === */

// the routine is used for tok_number
// It takes the current number value and creates a NumberExprAST node
std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken();
    return std::move(Result);
}

// TODO: not understand
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

// the routine is used for tok_identifier(variable)
std::unique_ptr<ExprAST> ParseIdentifierExpr() {
    std::string IdName = IdentifierStr;

    getNextToken();

    if (CurToken != '(') {
        return std::make_unique<VariableExprAST>(IdName);
    }

    getNextToken();
    std::vector<std::unique_ptr<ExprAST>> Args;

    if (CurToken != ')') {
        while (true)
        {
            if (auto Arg = ParseExpression()) {
                Args.push_back(std::move(Arg));
            } else {
                return nullptr;
            }

            if (CurToken == ')') {
                break;
            }

            if (CurToken != ',') {
                return LogError("Expected ')' or ',' in argument list");
            }
            getNextToken();
        }
    }
    getNextToken();
    return std::make_unique<CallExprAST>(IdName, std::move(Args));
}

// 对上述三个 Parse 的汇总，它们属于 Primary
std::unique_ptr<ExprAST> ParsePrimary() {
    switch (CurToken)
    {
    case tok_identifier:
        return ParseIdentifierExpr();
    case tok_number:
        return ParseNumberExpr();
    case '(':
        return ParseParentExpr();
    default:
        return LogError("Unknown token when expecting an expression");
    }
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

// Parse Function 模版
std::unique_ptr<PrototypeAST> ParsePrototype() {
    if (CurToken != tok_identifier) {
        return LogErrorP("Expected funciton name in prototype");
    }

    std::string FnName = IdentifierStr; // Function name
    getNextToken();

    if (CurToken != '(') {
        return LogErrorP("Expected '(' in prototype");
    }

    std::vector<std::string> ArgNames;  // Arguments' name
    while (getNextToken() == tok_identifier) {
        ArgNames.push_back(IdentifierStr);
    }

    if (CurToken != ')') {
        return LogErrorP("Expected ')' in prototype");
    }

    getNextToken();
    return std::make_unique<PrototypeAST>(FnName, std::move(ArgNames));
}

// Parse Funciton 定义
std::unique_ptr<FunctionAST> ParseDefinition() {
    getNextToken();

    auto Proto = ParsePrototype();
    if (!Proto) {
        return nullptr;
    }

    if (auto E = ParseExpression()) {
        return std::make_unique<FunctionAST>(std::move(Proto), std::move(E));
    }

    return nullptr;
}

std::unique_ptr<FunctionAST> ParseTopLevelExpr() {
    if (auto E = ParseExpression()) {
        auto proto = std::make_unique<PrototypeAST>("__anon_expr", std::vector<std::string>());
        return std::make_unique<FunctionAST>(std::move(Proto), std::move(E));
    }

    return nullptr;
}

std::unique_ptr<PrototypeAST> ParseExtern() {
    getNextToken();
    return ParsePrototype();
}