#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H

#include <iostream>

using namespace std;

class stringProcessing {
public:
string stripNonAlphaNum (std::string input);

private:
bool isAlphaNum (char input);

};

#endif