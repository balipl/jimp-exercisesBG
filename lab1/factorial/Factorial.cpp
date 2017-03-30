//
// Created by mwypych on 02.02.17.
//x
#include "Factorial.h"

int factorial(int value) {
    int wynik;

    if (value < 0) {
        wynik = 1;
        for (int k = value; k < 0; ++k) {
            wynik = wynik * k;
        }
    } else if (value < 13) {
        wynik = 1;
        for (int k = value; k > 0; --k) {
            wynik = wynik * k;
        }
    } else if (value >= 13) {
        wynik = 0;
    }

    return wynik;
}
