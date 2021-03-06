#ifndef ARGUMENT_PARSING_H
#define ARGUMENT_PARSING_H

#include "programmerDetails.h"

namespace ArgumentParsing
{
constexpr const char arguments[][2][60] =
{
    {"firstname", "student's first name"},
    {"surname",   "student's surname"},
    {"mail",      "student's e-mail (preferred not gmail)"},
    {"bookId",    "student book id number"},
    {"song",      "song suggested by student during the colloquium checking"}
};
constexpr unsigned argumensCount = sizeof(arguments) / sizeof(arguments[0]);

void reactToProgramArgumentsPossibilyExit(int argc, char* argv[]);
} // namespace ArgumentParsing

#endif // ARGUMENT_PARSING_H
