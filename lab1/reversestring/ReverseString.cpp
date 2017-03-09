//
// Created by ASUSTek on 2017-03-08.
//

#include "ReverseString.h"

using namespace std;

string reverse(string str){

    string str1;
    int length = str.length();
    for(int x=0; x<length; ++x)
    {
        str1 = str1 + str[length-x-1];
    }
    return str1;
}