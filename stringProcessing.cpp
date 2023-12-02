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
