//
// Created by Grove on 2017-04-27.
//

#include "Shape.h"

Trojkat::Trojkat() : h_(0){

}

Trojkat::Trojkat(double h) {
h_ = h;
}

Trojkat::~Trojkat() {

}

void Trojkat::rysuj() {
    for (int i = 0; i <h_; ++i) {
        for (int j = 0; j <= i ; ++j) {
            std::cout << "x";
        }
        std::cout << std::endl;
    }
}

Kwadrat::Kwadrat() : a_(0) {

}

Kwadrat::Kwadrat(double a) {
a_ = a;
}

Kwadrat::~Kwadrat() {

}

void Kwadrat::rysuj() {
    for (int i = 0; i < a_; ++i) {
        for (int j = 0; j < a_; ++j) {
            std::cout << "x";
        }
        std::cout << std::endl;
    }
}

Kolo::Kolo() : r_(0) {

}

Kolo::Kolo(double r) {
r_ = r;
}

Kolo::~Kolo() {

}

void Kolo::rysuj() {
std::cout << "    xxx\n"
             "   xxxxx\n"
             "  xxxxxxx\n"
             "  xxxxxxx  \n"
             "   xxxxx\n"
             "    xxx\n";
}
