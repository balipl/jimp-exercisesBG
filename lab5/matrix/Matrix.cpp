//
// Created by ASUSTek on 2017-04-05.
//

#include "Matrix.h"

namespace algebra {
    Matrix::Matrix() {
    }

    Matrix::Matrix(int n_rows, int n_cols) {
        size_.first = n_rows;
        size_.second = n_cols;

        matrix_.resize(n_rows);

        for (int i = 0; i < n_rows; ++i) {
            matrix_[i].resize(n_cols);
        }
    }

    Matrix::Matrix(const Matrix &matrix) {
        size_=matrix.Size();
        matrix_ = matrix.matrix_;
    }

    std::complex<double> Matrix::Get(int n_rows, int n_cols) const {
        return matrix_[n_rows][n_cols];
    }

    void Matrix::Set(int, int, std::complex<double>) {

    }

    std::pair<size_t, size_t> Matrix::Size() const {
        return size_;
    }

    std::string Matrix::Print() const {
        std::string exit = "[" ;

        for (int i = 0; i < size_.first; ++i) {
            for (int j = 0; j < size_.second; ++j) {

                std::stringstream real;
                std::string real_string;
                real << matrix_[i][j].real();
                real >> real_string;

                std::stringstream imag;
                std::string imag_string;
                imag << matrix_[i][j].imag();
                imag >> imag_string;


                exit = exit + real_string + "i" + imag_string;
                if(j< size_.second - 1) exit += ", ";
            }
            if(i < size_.first -1) exit += "; ";

        }
        exit += "]";

        return exit;
    }

    Matrix::~Matrix() {

    }

    Matrix Matrix::Add(const Matrix &m2) const {
        Matrix m3;
        m3.size_.first = m2.size_.first;
        m3.size_.second = m2.size_.first;

        m3.matrix_.resize(m3.size_.first);

        for (int i = 0; i < m3.size_.first; ++i) {
            m3.matrix_[i].resize(m3.size_.second);
        }


        for (int i = 0; i < size_.first; ++i) {
            for (int j = 0; j <size_.second ; ++j) {
                m3.matrix_[i][j] = matrix_[i][j] + m2.matrix_[i][j];
            }
        }
        return m3;
    }

    Matrix Matrix::Sub(const Matrix &m2) const {
        Matrix m3;
        m3.size_.first = m2.size_.first;
        m3.size_.second = m2.size_.first;

        m3.matrix_.resize(m3.size_.first);

        for (int i = 0; i < m3.size_.first; ++i) {
            m3.matrix_[i].resize(m3.size_.second);
        }


        for (int i = 0; i < size_.first; ++i) {
            for (int j = 0; j <size_.second ; ++j) {
                m3.matrix_[i][j] = matrix_[i][j] - m2.matrix_[i][j];
            }
        }
        return m3;
    }

    Matrix Matrix::Mul(const Matrix &m2) const {

        Matrix m3;

        if (size_.second == m2.size_.first) {
//        std::cout << size_.first << size_.second;
        m3.size_.first = size_.first;
        m3.size_.second = m2.size_.second;

        m3.matrix_.resize(m3.size_.first);

        for (int i = 0; i < m3.size_.first; ++i) {
            m3.matrix_[i].resize(m3.size_.second);
        }
        //std::cout << size_.first << size_.second << m2.size_.first << m2.size_.second;



            for (int j = 0; j < m3.size_.first; ++j) {
                for (int i = 0; i < m3.size_.second; ++i) {
                    m3.matrix_[j][i] = 0;
                    for (int k = 0; k < m2.size_.first; ++k) {
                        m3.matrix_[j][i] = m3.matrix_[j][i] + matrix_[j][k] * m2.matrix_[k][i];
                    }
                }
            }
        }
        return m3;
    }

    Matrix Matrix::Div(const Matrix &m2) const {
        return Matrix();
    }

    Matrix Matrix::Pow(int pow) {
        Matrix m3;

        if(size_.first != size_.second)
            return m3;

        m3.size_.first = size_.first;
        m3.size_.second = size_.first;

        m3.matrix_.resize(m3.size_.first);

        for (int i = 0; i < m3.size_.first; ++i) {
            m3.matrix_[i].resize(m3.size_.second);
        }

        if(pow == 0 )
        {
            for (int i = 0; i < m3.size_.first; ++i) {
                m3.matrix_[i][i] = 1;
            }
        }

        if(pow > 0)
        {
            for (int i = 0; i < size_.first; ++i) {
                for (int j = 0; j < size_.second; ++j) {
                    m3.matrix_[i][j] = matrix_[i][j];
                }
            }

            for (int k = 0; k < pow - 1; ++k) {
                m3 = m3.Mul(*this);
            }


        }

        return m3;

    }


}