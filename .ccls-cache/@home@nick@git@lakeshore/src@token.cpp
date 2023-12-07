#include "token.h"

/* Token::Token() {} */

Token::Token(const TokenType type, 
             const std::string lexeme, 
             const void* literal, 
             const int line) {}
Token::~Token() {}

std::string Token::toString()
{
    return TOKENS.at(Token::type) + " " + Token::lexeme + " " ; //+ literal; 
}


