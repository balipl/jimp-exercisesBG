//
// Created by ASUSTek on 2017-04-02.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <string>

class Matrix {
public:
    Matrix();

    Matrix(int kol, int wier);

    Matrix(std::string MatLab);

    //Matrix(const Matrix &matrix);

    ~Matrix();

    int GetSzer() const;
    int GetWys() const;
    std::string GetMac(int a, int b) const;


private:
    int wysokosc_;
    int szerokosc_;
    int **macierz = new int *[szerokosc_];

    for ( int i = 0; i < szerokosc_ ; i++){
        macierz[i] = new int [wysokosc_];}
};


#endif //JIMP_EXERCISES_MATRIX_H
