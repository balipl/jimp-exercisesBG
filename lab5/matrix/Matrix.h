//
// Created by ASUSTek on 2017-04-05.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <initializer_list>
#include <complex>
#include <vector>
#include <string>
#include <sstream>

namespace algebra {

    class Matrix {
    public:
        Matrix();

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &list) : matrix_(list) {
            size_.first = matrix_.size();
            size_.second = matrix_[0].size();
        };

        Matrix(int n_rows, int n_cols);
        Matrix(const Matrix &matrix);
        std::complex<double> Get(int n_rows, int n_cols) const;
        void Set(int, int, std::complex<double>);
        std::pair<size_t, size_t > Size() const;
        std::string Print() const;
        ~Matrix();

        Matrix Add(const Matrix &m2)const;
        Matrix Sub(const Matrix &m2)const;
        Matrix Mul(const Matrix &m2)const;
        Matrix Div(const Matrix &m2)const;
        Matrix Pow(int pow);

        int moja_funkcja();

    private:
        std::vector<std::vector<std::complex<double>>> matrix_;
        std::pair<size_t, size_t> size_;

    };

}
#endif //JIMP_EXERCISES_MATRIX_H
