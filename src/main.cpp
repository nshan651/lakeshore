#include <iostream>
#include "CLI/CLI.hpp"

#include "errors.h"
#include "lakeshore.h"

int main (int argc, char *argv[])
{
    std::string filepath;

    CLI::App app{"The Lakeshore programming language."};

    app.add_option("path", filepath, "Input file path"); 

    CLI11_PARSE(app, argc, argv);

    std::unique_ptr<Lakeshore> pLakeshore = std::make_unique<Lakeshore>();

    if (filepath.empty())
    {
        Lakeshore::runPrompt();
    }
    else
    {
        Lakeshore::runFile(filepath);
    }

    return 0;
}
