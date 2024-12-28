#include <iostream>
#include <map>
#include <string>

#pragma once

enum TokenType {
  /* Basic type literals */
  IDENT,  // main
  INT,    // 123
  FLOAT,  // 1.23
  CHAR,   // 'a'
  STRING, // "abc"
  NUMBER,

  /* Single-character tokens. */
  LPAREN,    // (
  LBRACK,    // [
  LBRACE,    // {
  RPAREN,    // )
  RBRACK,    // ]
  RBRACE,    // }
  COMMA,     // ,
  PERIOD,    // .
  SEMICOLON, // ;
  COLON,     // :

  /* Arithmetic operators */
  ADD, // +
  SUB, // -
  MUL, // *
  DIV, // /
  MOD, // %
  POS, // +5
  NEG, // -5

  /* Logical comparisons */
  EQL,    // ==
  LT,     // <
  GT,     // >
  ASSIGN, // =
  NOT,    // !
  NEQ,    // !=
  LEQ,    // <=
  GEQ,    // >=

  /* Bitwise operators */
  AND, // &
  OR,  // |
  XOR, // ^

  /* String concatenation */
  CONCAT,

  /* Keywords */
  BREAK,
  CASE,
  CLASS,
  CONTINUE,
  DEF,
  DEFAULT,
  ELSE,
  FALSE,
  FOR,
  FUN,
  IF,
  IMPORT,
  LET,
  MAP,
  PACKAGE,
  THEN,
  NIL,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,

  /* END OF FUNCTION (using END to avoid namespace collision) */
  END,
};

const std::map<TokenType, std::string> TOKENS
{
    {IDENT, "IDENT"},
    {INT, "INT"},
    {FLOAT, "FLOAT"},
    {CHAR, "CHAR"},
    {STRING, "STRING"},
    {LPAREN, "("},
    {LBRACK, "["},
    {LBRACE, "{"},
    {RPAREN, ")"},
    {RBRACK, "]"},
    {RBRACE, "}"},
    {COMMA, ","},
    {PERIOD, "."},
    {SEMICOLON, ";"},
    {COLON, ":"},
    {ADD, "+"},
    {SUB, "-"},
    {MUL, "*"},
    {DIV, "/"},
    {MOD, "%"},
    {POS, "+5"},
    {NEG, "-5"},
    {EQL, "=="},
    {LT, "<"},
    {GT, ">"},
    {ASSIGN, "="},
    {NOT, "!"},
    {NEQ, "!="},
    {LEQ, "<="},
    {GEQ, ">="},
    {AND, "&"},
    {OR, "|"},
    {XOR, "^"},
    {CONCAT, "concat"},
    {BREAK, "break"},
    {CASE, "case"},
    {CONTINUE, "continue"},
    {DEF, "def"},
    {DEFAULT, "default"},
    {ELSE, "else"},
    {FOR, "for"},
    {IF, "if"},
    {IMPORT, "import"},
    {LET, "let"},
    {MAP, "map"},
    {PACKAGE, "package"},
    {THEN, "then"},
    {END, "eof"}
};

class Token 
{
  public:
    const TokenType type;
    const std::string lexeme;
    const void* literal;
    const int line;
  
  Token(const TokenType type, 
	const std::string lexeme, 
	const void* literal, 
	const int line);
  
  ~Token();

  std::string toString();
};
