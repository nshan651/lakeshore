#include <iostream>
#include <map>
#include <string>

#pragma once

enum TokenType {
  /* Basic type literals. */
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

  /* Arithmetic operators. */
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
  /* Basic type literals. */
  {IDENT, "IDENT"},
  {INT, "INT"},
  {FLOAT, "FLOAT"},
  {CHAR, "CHAR"},
  {STRING, "STRING"},
  {NUMBER, "NUMBER"},

  /* Single-character tokens. */
  {LPAREN, "LPAREN"},
  {LBRACK, "LBRACK"},
  {LBRACE, "LBRACE"},
  {RPAREN, "RPAREN"},
  {RBRACK, "RBRACK"},
  {RBRACE, "RBRACE"},
  {COMMA, "COMMA"},
  {PERIOD, "PERIOD"},
  {SEMICOLON, "SEMICOLON"},
  {COLON, "COLON"},

  /* Arithmetic operators. */
  {ADD, "ADD"},
  {SUB, "SUB"},
  {MUL, "MUL"},
  {DIV, "DIV"},
  {MOD, "MOD"},
  {POS, "POS"},
  {NEG, "NEG"},

  /* Logical comparisons */
  {EQL, "EQL"},
  {LT, "LT"},
  {GT, "GT"},
  {ASSIGN, "ASSIGN"},
  {NOT, "NOT"},
  {NEQ, "NEQ"},
  {LEQ, "LEQ"},
  {GEQ, "GEQ"},

  /* Bitwise operators */
  {AND, "AND"},
  {OR, "OR"},
  {XOR, "XOR"},

  /* String concatenation */
  {CONCAT, "CONCAT"},

  /* Keywords */
  {BREAK, "BREAK"},
  {CASE, "CASE"},
  {CONTINUE, "CONTINUE"},
  {DEF, "DEF"},
  {DEFAULT, "DEFAULT"},
  {ELSE, "ELSE"},
  {FOR, "FOR"},
  {IF, "IF"},
  {IMPORT, "IMPORT"},
  {LET, "LET"},
  {MAP, "MAP"},
  {PACKAGE, "PACKAGE"},
  {THEN, "THEN"},
  {END, "EOF"}
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
