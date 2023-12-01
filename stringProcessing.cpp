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
            cout << "word: " << word.str() << endl;
        }

    }
    cout << word.str() << endl;
    cout << "test" << endl;
    return word.str();
    
}

bool stringProcessing::isAlphaNum (char input) {
    if (int(input) > 90 or int(input) < 65) {
        return false;
    }
    if (int(input) > 122 or int(input) < 97) {
        return false;
    }
    return true;
}
