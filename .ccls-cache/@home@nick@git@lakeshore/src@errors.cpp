#include "errors.h"

void error(const int line, const std::string message)
{
    report(line, "", message);
}

void report(const int line, const std::string where, const std::string message)
{
    spdlog::error("[line {}]{}: {}", line, where, message); 
}

