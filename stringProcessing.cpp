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

string stringProcessing::stripNonAlphaNum (std::string input) {
    ostringstream word;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (isAlphaNum(input[i])) {
            word << input[i];
        }

    }
    cout << "word after: " << word.str() << endl;
    return word.str();
}

bool stringProcessing::isAlphaNum (char input) {
    cerr  << int(input) << endl;
    if (int(input) < 90 and int(input) > 65 ) {
        return true;
    }
    if (int(input) < 122 and int(input) > 97) {
        return true;
        
    }
    cerr << "executing isAlphaNum: " << endl;
    return false;
}
