/*
file: stringProcessing.cpp
name: Cullen, Frank
date: December 4, 2023
project: proj 4 gerp
description: this is the implementation of the class that contains the method 
        of stripping non-alpha characters from the input string
*/

#include <string>
#include "stringProcessing.h"
#include <iostream>
#include <sstream>

using namespace std;

string stripNonAlphaNum (std::string input) {
    std::string result = input;

    // Remove non-alphanumeric characters from the beginning
    while (!result.empty() && !isAlphaNum(result.front())) {
        result.erase(0, 1);
    }

    // Remove non-alphanumeric characters from the end
    while (!result.empty() && !isAlphaNum(result.back())) {
        result.pop_back();
    }

    return result;
}

bool isAlphaNum (char input) {
    if (int(input) <= 90 and int(input) >= 65 ) {
        return true;
    }
    if (int(input) <= 122 and int(input) >= 97) {
        return true;
        
    }
    if (int(input) > 47 and int(input) < 58) {
        return true;
    }
    return false;
}


