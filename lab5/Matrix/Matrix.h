//
// Created by ASUSTek on 2017-04-02.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <string>

namespace algebra {
    class Matrix {
    public:
        Matrix(); //konstruktor bezparametryczny

        Matrix(int n_rows, int n_cols); //konstruktor parametryczny rozmiar

        Matrix(std::string MatLab); //konstruktor parametryczny matlab

        Matrix(const Matrix &matrix);

        ~Matrix();


        std::complex<double> GetElem(int n_rows, int n_cols);

        void SetElem(int n_rows, int n_cols, std::complex<double> element);


    private:
        int n_rows_;
        int n_cols_;
        std::complex<double> **matrix_;

    };
}

#endif //JIMP_EXERCISES_MATRIX_H
