/*
file: stringProcessing.h
name: Cullen, Frank
date: December 4, 2023
project: proj 4 gerp
description: this is a class that contains the method of stripping non-alpha
        characters from the input string
*/


#include <iostream>

using namespace std;

/*
stripNonAlphaNum
purpose: strip all the non-alphanumeric (alphabetic) characters from the given 
        input.
Input: string input
output: string without the non-alphanumeric characters
*/
string stripNonAlphaNum (std::string input);

/*
isAlphaNum
purpose: private class function used to determine whether the given char
        is an alphanumeric character or not
Input: char input
output: boolean value that returns true if the char is an alphanumeric and false
        otherwise
*/
bool isAlphaNum (char input);



