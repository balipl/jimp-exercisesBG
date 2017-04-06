//
// Created by ASUSTek on 2017-03-09.
//x
#include "GreatestProduct.h"

using std::vector;
using std::sort;

int GreatestProduct(const vector<int> &numbers, int k) {
    vector<int> numbers_edited = numbers;
    int result = 1;
    int positive = 1;
    int negative = 0;

    sort(numbers_edited.begin(), numbers_edited.end());

    for (int i = 0; i < k / 2; ++i) {
        int first_positive = numbers_edited[numbers_edited.size() - positive - 1];
        int second_positive = numbers_edited[numbers_edited.size() - positive];
        int first_negative = numbers_edited[negative];
        int second_negative = numbers_edited[negative + 1];

        if (second_positive * first_positive > first_negative * second_negative or (second_positive < 0 and k % 2 != 0)) {
            result = result * second_positive * first_positive;
            positive += 2;
        } else {
            result = result * first_negative * second_negative;
            negative += 2;
        }
    }
    int second_positive = numbers_edited[numbers_edited.size() - positive];

    if (k % 2 != 0) {
        result = result * second_positive;
    }
    return result;


}

