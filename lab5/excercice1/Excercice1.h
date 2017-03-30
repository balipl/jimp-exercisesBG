//
// Created by ASUSTek on 2017-03-30.
//

#ifndef JIMP_EXERCISES_EXCERCICE1_H
#define JIMP_EXERCISES_EXCERCICE1_H

#include <iostream>
#include <cstring>

class XXX {
public:
    //w zeszłym odcinku:
    //domyślny konstruktor
    XXX();
    //konstruktory parametryczne
    XXX(int param);
    XXX(const std::string name);

    //Rule of five://
    //1. konstruktor kopiujący
    XXX(const XXX &xxx);
    //2. konstruktor przenoszący
    XXX(XXX &&xxx);
    //3. operator przypisania kopiujący
    XXX &operator=(const XXX &xxx);
    //4. operator przypisania przenoszący
    XXX &operator=(XXX &&xxx);
    //5. Destruktor
    ~XXX();
private:
    char *name_;

    void MojaNowaFunkcja(const XXX &xxx);

    void MojaDrugaNowaFunkcja(XXX &&xxx);
};


#endif //JIMP_EXERCISES_EXCERCICE1_H
