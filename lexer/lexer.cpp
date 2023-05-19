#include "lexer/lexer.h"
#include "lexer/token.h"

int CurToken;
std::string IdentifierStr;
double NumVal;

// Actaully, the implementation of the lexer is the below function getToken()
int getToken() {
    static int LastChar = ' ';
    
    // whitespaces should not be in consideration
    while (isspace(LastChar)) {
        LastChar = getchar();
    }

}

int getNextToken() {
    return CurToken = getToken();
}