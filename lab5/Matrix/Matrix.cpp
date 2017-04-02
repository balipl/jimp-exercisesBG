//
// Created by ASUSTek on 2017-04-02.
//

#include "Matrix.h"

using std::complex;
using std::string;

Matrix::Matrix(){}

Matrix::~Matrix(){}

//konstruktor paramterowy okreslajacy wymiary macierzy
Matrix::Matrix(int szerokosc, int wysokosc){
    szerokosc_= szerokosc;
    wysokosc_=wysokosc;
}
Matrix::Matrix(string matlab){
    int wysokosc = 1;
    int szerokosc = 1;
    int i = 0;
    while(matlab[i]!='\0')
    {
        if(matlab[i]==' ' and wysokosc == 1)
        {
            szerokosc++;
       }
       if(matlab[i]==';')
        {
            wysokosc++;
        }
        i++;
   }

    i=1;
    int szer = 0;
    int wys = 0;
    while(matlab[i]!='\0')
    {
        if(matlab[i]!= ' ' and matlab[i]!= ']' and matlab[i]!=';'){
            string slowo = "";
            while(matlab[i]!= ' ' and matlab[i]!= ']' and matlab[i]!=';')
            {
               slowo+=matlab[i];
               i++;
            }
            macierz_[szer][wys] = slowo;
            szer+=1;
            }
        if(matlab[i]==';')
        {
            wys+=1;
            szer = 0;
        }
        if(matlab[i]!= '\0')
        {i++;}
    }

    szerokosc_ = szerokosc;
    wysokosc_ = wysokosc;
}
//
//Matrix::Matrix(const Matrix& matrix) {
//    size_t dlugosc = matrix.wysokosc_;
//    size_t szerokosc = matrix.szerokosc_;
////    macierz = new complex<double>[5][5];
////    std::strcpy(macierz,matrix.macierz);
//
//    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
//    //ale ze skopiowaną informacją
//}

int Matrix::GetSzer() const {
    return szerokosc_;
}

int Matrix::GetWys() const {
    return wysokosc_;
}

void Matrix:Add()

string Matrix::GetMac(int a,int b) const {
    return macierz_[a][b];
}
