//
// Created by ASUSTek on 2017-03-08.
//x

#include "ReverseString.h"

using std::string;

string reverse(string str) {
    string reversedString;
    int length = str.length();
    for (int x = 0; x < length; ++x) {
        reversedString = reversedString + str[length - x - 1];
    }

    return reversedString;
}