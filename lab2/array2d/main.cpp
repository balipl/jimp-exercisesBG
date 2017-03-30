//
// Created by ASUSTek on 2017-03-11.
//
#include "Array2D.h"

int main()
{
    int** tab = Array2D(5,7);
    std::cout << "HEHE" << tab[0][5];
    DeleteArray2D(tab,5,7);
    return 0;
}