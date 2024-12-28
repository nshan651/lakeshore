#include "token.h"

Token::Token(const TokenType type, 
             const std::string lexeme, 
             const void* literal, 
             const int line)
  : type(type), lexeme(lexeme), literal(literal), line(line) {}

Token::~Token() {}

std::string Token::toString()
{
    return TOKENS.at(Token::type) + " " + Token::lexeme + " " ; //+ literal; 
}


