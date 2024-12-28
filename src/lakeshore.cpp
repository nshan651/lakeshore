#include <iostream>
#include "lakeshore.h"
#include "lexer.h"
#include "errors.h"

bool Lakeshore::hadError = false;

Lakeshore::Lakeshore() {}

Lakeshore::~Lakeshore() {}

void Lakeshore::runFile(const std::string filepath)
{
  std::ifstream file(filepath, std::ios::binary);
  
  if (!file)
  {
      error(0, "File not found");
      return;
  }
  
  std::ostringstream fileContent;
  fileContent << file.rdbuf();
  file.close();
  
  std::string content = fileContent.str();
  
  run(content);
  
  if (Lakeshore::hadError) std::exit(65);
}

void Lakeshore::runPrompt()
{
  for (;;) {
    std::cout << "> ";
    std::string line;
    std::getline(std::cin, line);
    
    if (line.empty()) break;
    
    run(line);

    Lakeshore::hadError = false;
  } 
}

void Lakeshore::run(const std::string source)
{
  Lexer lexer(source);
  std::vector<Token> tokens = lexer.scanTokens();

  // Just print out tokens for now.
  for (auto token : tokens)
    std::cout << token.toString() << std::endl;
}
