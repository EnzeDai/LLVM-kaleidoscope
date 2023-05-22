#include "lexer/lexer.h"
#include "lexer/token.h"

int CurToken;
std::string IdentifierStr;
double NumVal;

// Actaully, the implementation of the lexer is the below function getToken()
int getToken() {
    static int LastChar = ' ';
    
    // Whitespaces should not be in consideration
    while (isspace(LastChar)) {
        LastChar = getchar();
    }

    // Distinguish the identifier
    if (isalpha(LastChar)) {
        IdentifierStr = LastChar;

        // Get next char until it's not a letter or number
        while (isalnum(LastChar = getchar())) {
            IdentifierStr += LastChar;
        }

        if (IdentifierStr == "def") {
            return tok_def;
        }

        if (IdentifierStr == "extern") {
            return tok_extern;
        }

        return tok_identifier;
    }

    // Distinguish the numerical variable
    if (isdigit(LastChar) || LastChar == '.') {
        std::string NumStr;

        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');

        // Convert string to double
        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    // Cope with comments by skipping to the end of the line
    if (LastChar == '#') {
        do {
            LastChar = getchar();
        } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        // Not the end of the file, call getToken() recursively
        if (LastChar != EOF) {
            return getToken();
        }
    }

    // None of the above circumstances matched
    if (LastChar == EOF) {
        return tok_eof;
    }

    int ThisChar = LastChar;
    LastChar = getchar();

    return ThisChar;
}

int getNextToken() {
    return CurToken = getToken();
}
