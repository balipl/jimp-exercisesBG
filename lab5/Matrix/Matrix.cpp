//
// Created by ASUSTek on 2017-04-02.
//

#include "Matrix.h"

using std::complex;
using std::string;

namespace algebra {
    Matrix::Matrix() {}

    Matrix::~Matrix() {}

    Matrix::Matrix(const Matrix &matrix)
    {
        n_rows_ = matrix.n_rows_;
        n_cols_ = matrix.n_cols_;

        matrix_ = new complex<double> *[n_rows_];

        for (int i = 0; i <n_rows_ ; ++i) {
            matrix_[i] = new complex<double>[n_cols_];
        }
        for (int j = 0; j < n_rows_; ++j) {
            for (int k = 0; k < n_cols_; ++k) {
                matrix_[j][k] = matrix.matrix_[j][k];
            }
        }
    }

    Matrix::Matrix(int n_rows, int n_cols)
    {
        n_rows_ = n_rows;
        n_cols_ = n_cols;
        matrix_ = new complex<double> *[n_rows];

        for (int i = 0 ; i < n_rows ; i++)
        {
            matrix_[i] = new complex<double>[n_cols];
        }

        for (int j = 0; j <  n_rows; ++j) {
            for (int k = 0; k < n_cols; ++k) {
                matrix_[j][k] = 0;
            }
        }
    }




    Matrix::Matrix(string MatLab) {
        int wysokosc = 1;
        int szerokosc = 1;
        int i = 0;
        while (MatLab[i] != '\0') {
            if (MatLab[i] == ' ' and wysokosc == 1) {
                szerokosc++;
            }
            if (MatLab[i] == ';') {
                wysokosc++;
            }
            i++;
        }

        i = 1;
        int szer = 0;
        int wys = 0;
        while (MatLab[i] != '\0') {
            if (MatLab[i] != ' ' and MatLab[i] != ']' and MatLab[i] != ';') {
                string slowo = "";
                while (MatLab[i] != ' ' and MatLab[i] != ']' and MatLab[i] != ';') {
                    slowo += MatLab[i];
                    i++;
                }
                matrix_[szer][wys] = slowo;
                szer += 1;
            }
            if (MatLab[i] == ';') {
                wys += 1;
                szer = 0;
            }
            if (MatLab[i] != '\0') { i++; }
        }

        szerokosc_ = szerokosc;
        wysokosc_ = wysokosc;
    }



    void Matrix::SetElem(int n_rows, int n_cols, std::complex<double> element) {
        matrix_[n_rows][n_cols] = element;
    }

    complex<double> Matrix::GetElem(int n_rows, int n_cols) {
        return matrix_[n_rows][n_cols];
    }
}