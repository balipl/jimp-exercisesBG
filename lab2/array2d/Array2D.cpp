//
// Created by ASUSTek on 2017-03-11.
//

#include "Array2D.h"

int **Array2D(int n_rows, int n_columns){
    //2 * bo zwraca wskanizk na wskaznik

    int **tab = new int*[n_columns]

    for (int i = 0; i < ; ++i) {
        tab[i]=new int(n_rows)

    }

    wypelnic



}
void DeleteArray2D(int **array, int n_rows, int n_columns){

    //usuwa te tablice tablicą for,a potem ostatnia instrukcja usuwa tablice wskaznikow

    for (int i = 0; i < ; ++i) {
        delete [] array[i]
    }
    delete [] array
}
