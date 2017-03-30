//
// Created by ASUSTek on 2017-03-09.
//x
#include <Palindrome.h>

#include "DoubleBasePalindromes.h"

using std::string;
using std::to_string;


string DecToBin(int decimal) {
    string binary;
    string reversed_binary;

    while (decimal != 0) {
        binary += to_string(decimal % 2);
        decimal = decimal / 2;
    }

    int binary_length = binary.length();

    for (int i = 0; i < binary_length; i++) {
        reversed_binary += binary[binary_length - i - 1];
    }

    return reversed_binary;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    uint64_t sum = 0;
    string tested_number;

    for (int k = 0; k <= max_vaule_exculsive; k++) {
        tested_number = to_string(k);
        if (is_palindrome(tested_number) == true and is_palindrome(DecToBin(k)) == true)
            sum += k;
    }

    return sum;
}
