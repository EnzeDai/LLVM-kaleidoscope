#ifndef __LEXER_H__
#define __LEXER_H__

#include <cstdlib>
#include <string>

// CurToken is the token the parser is processing right now.
extern int CurToken;
// getToken fetches another token from the lexer.
int getToken();
// getNextToken updates CurToken by calling getToken.
int getNextToken();

extern std::string IdentifierStr;
extern double NumVal;

#endif