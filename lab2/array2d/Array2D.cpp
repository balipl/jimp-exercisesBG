//
// Created by ASUSTek on 2017-03-11.
//x

#include "Array2D.h"


int **Array2D(int n_rows, int n_columns){

    int** tab = new int*[n_columns];

    for (int i = 0; i < n_columns; ++i) {
        tab[i] = new int[n_rows];
    }

    FillArray2D(tab, n_rows, n_columns);
    //DeleteArray2D(tab,n_rows,n_columns);
    return tab;
}

void FillArray2D(int **tab, int n_rows, int n_columns) {
    int counter = 1;
    for (int i = 0; i < n_rows ; ++i) {
        for (int j = 0; j <n_columns ; ++j) {
            tab[i][j] = counter;
            counter++;
            //std::cout << tab[i][j] << " ";
        }
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i = 0; i < n_columns ; i+=1) {
        array[i] = nullptr;
        delete [] array[i];
        array[i] = nullptr;
    }
    array = nullptr;
    delete [] array;
    array = nullptr;
}
