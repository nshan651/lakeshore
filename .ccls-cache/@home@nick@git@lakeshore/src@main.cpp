#include <iostream>
#include "CLI/CLI.hpp"

#include "errors.h"
#include "lexer.h"

int main (int argc, char *argv[])
{
    std::string filepath;

    CLI::App app{"The Lakeshore programming language."};

    app.add_option("path", filepath, "Input file path"); 

    CLI11_PARSE(app, argc, argv);

    std::unique_ptr<Lexer> pLexer = std::make_unique<Lexer>();

    if (filepath.empty())
    {
        Lexer::runPrompt();
    }
    else
    {
        Lexer::runFile(filepath);
    }

    return 0;
}
