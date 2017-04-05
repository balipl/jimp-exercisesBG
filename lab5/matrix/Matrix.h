//
// Created by ASUSTek on 2017-04-05.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
namespace algebra {

    class Matrix {
    public:
        Matrix(); // konstruktor bezparametryczny

        ~Matrix();

        Matrix(const Matrix &matrix);

        Matrix(std::string MatLab); //parametryczny matlab

        Matrix(int n_rows, int n_cols); //parametryczny rows x cols


        std::complex<double> GetElem(int n_rows, int n_cols);

        void SetElem(int n_rows, int n_cols, std::complex<double> element);

    private:
        std::complex<double> **matrix_;
        int n_cols_, n_rows_;
    };

}

#endif //JIMP_EXERCISES_MATRIX_H

