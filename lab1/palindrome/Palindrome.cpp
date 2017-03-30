//
// Created by ASUSTek on 2017-03-09.
//

#include "Palindrome.h"


using std::string;

bool is_palindrome(string str) {
    string reversed = getString(str);

    if (str.compare(reversed) == 0)
        return true;
    else
        return false;
}

string getString(string str) {
    string reversed;
    int length = str.length();
    for (int x = 0; x < length; ++x) {
        reversed = reversed + str[length - x - 1];
    }

    return reversed;
}
