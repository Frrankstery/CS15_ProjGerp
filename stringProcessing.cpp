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
    ostringstream word;
    int len = input.length();
    char arr[len];
    for (int i = 0; i < len; i++) {
        arr[i] = input[i];
    }
    for (int i = 0; i < len; i++) {
        if (not isAlphaNum(arr[i])) {
            arr[i] = ' ';
        }
        if (isAlphaNum(arr[i])) {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (not isAlphaNum(arr[len - i])) {
            arr[len - i] = ' ';
        }
        if (isAlphaNum(arr[i])) {
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] != ' ') {
            word << arr[i];
        }
    }
    return word.str();
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
