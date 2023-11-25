#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#pragma once

class Lexer
{
    public:

    Lexer();

    ~Lexer();

    static void runFile(const std::string filepath);

    static void runPrompt(void);

    static void run(const std::string source);
}; 

