#include "lexer.h"
#include "token.h"
#include "errors.h"

// Initialize keyword mapping.
const std::unordered_map<std::string, TokenType> Lexer::keywords =
{
  {"and", AND},
  {"class", CLASS},
  {"else", ELSE},
  {"false", FALSE},
  {"for", FOR},
  {"fun", FUN},
  {"if", IF},
  {"nil", NIL},
  {"or", OR},
  {"print", PRINT},
  {"return", RETURN},
  {"super", SUPER},
  {"this", THIS},
  {"true", TRUE},
  {"var", VAR},
  {"while", WHILE}
};


Lexer::Lexer(const std::string source)
  : source(source) { }

Lexer::~Lexer() {}

std::vector<Token> Lexer::scanTokens()
{
  while (!isAtEnd()) {
    Lexer::start = Lexer::current;
    scanToken();
  }
    
  Lexer::tokens.emplace_back(TokenType::END, "", nullptr, 0);

  return Lexer::tokens;
}

void Lexer::scanToken()
{
  // Get the next char.
  char c = advance();

  switch (c) {
    /* Single char lexemes. */
    case '(': addToken(LPAREN); break;
    case ')': addToken(RPAREN); break;
    case '{': addToken(LBRACE); break;
    case '}': addToken(RBRACE); break;
    case ',': addToken(COMMA); break;
    case '.': addToken(PERIOD); break;
    case '-': addToken(SUB); break;
    case '+': addToken(ADD); break;
    case ';': addToken(SEMICOLON); break;
    case '*': addToken(MUL); break;

    /* Multi-char lexemes. */
    case '!': addToken(match('=') ? NEQ : NOT); break;
    case '=': addToken(match('=') ? EQL : ASSIGN); break;
    case '<': addToken(match('=') ? LEQ : LT); break;
    case '>': addToken(match('=') ? GEQ : GT); break;

    /* Division or comments. */
    case '/':
      if (match('/')) {
	while (peek() != '\n' && !isAtEnd()) advance();
      }
      else {
	addToken(DIV);
      }
      break;

    /* Skip over escape characters and blank lines. */
    case ' ':
    case '\r':
    case '\t':
      break;

    /* Increment newline. */
    case '\n': Lexer::line++; break;

    /* Handle string literals. */
    case '"': string(); break;

    default:
      /* Handle digits in the default case. */
      if (isDigit(c)) {
	number();
      }
      else if (isAlpha(c)) {
	identifier();
      }
      else {
	error(Lexer::line, "Unexpected character.");
      }
      break;
  }
}

/* Check if we've reached the end of the source. */
bool Lexer::isAtEnd()
{
  return Lexer::current >= Lexer::source.size();
}

/* Check if lexeme is a digit. */
bool Lexer::isDigit(char c)
{
  return c >= '0' && c <= '9';
}

/* Check if lexeme is an alpha. */
bool Lexer::isAlpha(char c)
{
  return (c >= 'a' && c <= 'z') ||
	 (c >= 'a' && c <= 'z') ||
	  c == '_';
}

/* Check if lexeme is an alphanumeric. */
bool Lexer::isAlphaNumeric(char c)
{
  return isAlpha(c) || isDigit(c);
}

/* Match the next char with the expected, used for compound lexemes. */
bool Lexer::match(char expected)
{
  if (isAtEnd() || Lexer::source.at(Lexer::current) != expected) {
    return false;
  }

  Lexer::current++;

  return true;
}

/* Advance by one character. */
char Lexer::advance()
{
  return Lexer::source.at(Lexer::current++);
}

char Lexer::peek()
{
  return isAtEnd() ?
    '\0' : Lexer::source.at(Lexer::current);
}

char Lexer::peekNext()
{
  return (Lexer::current + 1 >= Lexer::source.length()) ?
    '\0' : Lexer::source.at(Lexer::current + 1);
}

void Lexer::addToken(TokenType type)
{
  addToken(type, nullptr);
}

void Lexer::addToken(TokenType type, void* literal)
{
  std::string text =
    Lexer::source.substr(Lexer::start, Lexer::current - Lexer::start);
  Lexer::tokens.emplace_back(type, text, literal, Lexer::line);
}

/* Scan string literals. */
void Lexer::string()
{
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n') Lexer::line++;
    advance();
  }

  if (isAtEnd()) {
    error(Lexer::line, "Unterminated string.");
    return;
  }

  // The closing ".
  advance();

  std::string value = Lexer::source.substr(Lexer::start + 1,
					   Lexer::current - 1);

  addToken(STRING, static_cast<void*>(&value));
}

void Lexer::number()
{
  while (isDigit(peek())) advance();

  // Look for a fractional part.
  if (peek() == '.' && isDigit(peekNext())) {
    // Consume the "."
    advance();

    while (isDigit(peek())) advance();
  }

  double num = std::stod(Lexer::source.substr(Lexer::start,
					      Lexer::current - Lexer::start));

  addToken(NUMBER, static_cast<void*>(&num));
}

void Lexer::identifier()
{
  while (isAlphaNumeric(peek())) advance();

  std::string text =
    Lexer::source.substr(Lexer::start, Lexer::current - Lexer::start);

  auto it = keywords.find(text);

  if (it != keywords.end()) {
    addToken(it->second);
  }
  else {
    addToken(IDENT);
  }
}
