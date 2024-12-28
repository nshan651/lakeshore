#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#pragma once

class Lakeshore
{
  public:
    static bool hadError;

    Lakeshore();
    ~Lakeshore();

    static void runFile(const std::string filepath);

    static void runPrompt(void);

    static void run(const std::string source);
}; 

void runFile(const std::string filepath);
void runPrompt(void);
void run(const std::string source);
