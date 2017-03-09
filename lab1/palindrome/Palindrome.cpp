//
// Created by ASUSTek on 2017-03-09.
//

#include "Palindrome.h"

using namespace std;

bool is_palindrome(string str){

    string reverse;
    int length = str.length();
    for(int x=0; x<length; ++x)
    {
        reverse = reverse + str[length-x-1];
    }

    if(str.compare(reverse)==0)
        return true;
    else
        return false;
}
