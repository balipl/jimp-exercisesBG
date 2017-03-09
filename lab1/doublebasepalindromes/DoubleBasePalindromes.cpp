//
// Created by ASUSTek on 2017-03-09.
//
#include <Palindrome.h>

#include "DoubleBasePalindromes.h"

using namespace std;


string DecToBin(int dec){
    string bin;
    string reversed_bin;
    while(dec!=0)
    {
        bin = bin + to_string(dec%2);
        dec = dec / 2;
    }

    int bin_length = bin.length();
    for(int i=0; i<bin_length; i++)
    {
        reversed_bin = reversed_bin + bin[bin_length-i-1];
    }
    return reversed_bin;
}


uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t sum=0;
    for(int k=0; k<=max_vaule_exculsive; k++){
        string tested_number = to_string(k);
        if(is_palindrome(tested_number)==true and is_palindrome(DecToBin(k))==true)
            sum = sum + k ;
    }
return sum;
}
