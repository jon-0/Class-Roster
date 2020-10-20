#pragma once
#include <string>
enum DegreeType { SECURITY, NETWORKING, SOFTWARE }; //The three types of degrees

//The following array of strings is useful for printing labels equivalent to the enumerated values

static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORKING", "SOFTWARE" };

// You can use the enumerated value as an index
// degreeTypeStrings[SECURITY] yields the string "SECURITY" and
// degreeTypeStrings[NETWORKING] yields "NETWORKING"
