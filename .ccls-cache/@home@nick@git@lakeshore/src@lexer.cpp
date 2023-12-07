#include "lexer.h"
#include "errors.h"

bool Lexer::hadError = false;

Lexer::Lexer() {}

Lexer::~Lexer() {}

void Lexer::runFile(const std::string filepath)
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

    /* run(content); */

    if (Lexer::hadError) std::exit(65);
    
}

void Lexer::runPrompt()
{
    for (;;) {
        std::cout << "> ";
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) break;

        /* run(line); */
        Lexer::hadError = false;
    } 
}

void Lexer::run(const std::string source)
{
}
