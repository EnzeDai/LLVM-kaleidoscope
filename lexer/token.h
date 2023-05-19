#ifndef __TOKEN_H__
#define __TOKEN_H__

/* If the character is unknown, the lexer returns tokens ∈ [0, 200].
   Otherwise the lexer returns the below known things. */
enum Token {
    // End of file
    tok_eof = -1,

    // Commands
    tok_def = -2,
    tok_extern = -3,

    // Primary
    tok_identifier = -4,
    tok_number = -5,
};

#endif