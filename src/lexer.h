#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "token.h"

#pragma once

class Lexer
{
  public:
    Lexer(const std::string source);
    ~Lexer();

    std::vector<Token> scanTokens();
    void scanToken();
  
  private:
    std::string source;
    std::vector<Token> tokens;

    static const std::unordered_map<std::string, TokenType> keywords;

    int start = 0;
    int current = 0;
    int line = 1;

    bool isAtEnd();
    bool isDigit(char c);
    bool isAlpha(char c);
    bool isAlphaNumeric(char c);
    bool match(char expected);
    char advance();
    char peek();
    char peekNext();
    void addToken(TokenType type);
    void addToken(TokenType type, void *literal);
    void string();
    void number();
    void identifier();
};
