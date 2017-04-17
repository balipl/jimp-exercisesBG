//
// Created by ASUSTek on 2017-04-02.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H

#include <iostream>
#include <cstring>


class XXX {
public:
    //w zeszlyym odcinku:
    //domyslny konstruktor
    XXX();
    //konstruktory parametryczne
    XXX(int param);
    XXX(const std::string name);

    //Rule of five://
    //1. konstruktor kopiujacy
    XXX(const XXX &xxx);
    //2. konstruktor przenoszacy
    XXX(XXX &&xxx);
    //3. operator przypisania kopiujacy
    XXX &operator=(const XXX &xxx);
    //4. operator przypisania przenoszacy
    XXX &operator=(XXX &&xxx);
    //5. Destruktor
    ~XXX();
private:
    char *name_;

    void MojaNowaFunkcja(const XXX &xxx);

    void MojaDrugaNowaFunkcja(XXX &&xxx);
};


#endif //JIMP_EXERCISES_XXX_H
