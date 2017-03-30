//
// Created by ASUSTek on 2017-03-30.
//

#include "Excercice1.h"
using namespace std;

//konstruktor domyslny
XXX::XXX() : name_{new char[1024]} {
}
XXX::XXX(const std::string name){
}

//destruktor
XXX::~XXX() {
    delete [] name_;
}
//konstruktor kopiujacy
XXX::XXX(const XXX& xxx) {
    MojaNowaFunkcja(xxx);  //nizej sie to zrobilo i przenioslo tez komentarz
    //Teraz nowy obiekt pokazuje na nowy fragment pamięci,
    //ale ze skopiowaną informacją  przenoszacy ustawial swoj stan na zly a potem sie wymienial. A tutaj duplikujemy element alokujac mu pamiec
}

void XXX::MojaNowaFunkcja(const XXX &xxx) {
    size_t sz = strlen(xxx.name_);  //tu moze sie zjebac, jak \0 bedzie wczesniej. Poslugujemy sie int starem i nie szukamy po \0 tylko jawnie zapisujemyliczbe pamieci
    name_ = new char[sz];
    strcpy(name_, xxx.name_);
}

//operator przypisania:
XXX & XXX::operator=(const XXX& xxx) {
    //jeśli ktoś wpadł na pomysł x = x;
    if (this == &xxx) {
        return *this;
    }
    //w przyciwynym wypadku mamy x = y;
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie kopiowanie, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    size_t sz = strlen(xxx.name_);
    name_ = new char[sz];
    strcpy(name_,xxx.name_);
}
//konstruktor przenoszący:
XXX::XXX(XXX &&xxx) {
    MojaDrugaNowaFunkcja(std::move(xxx)); //stad wzialem druga funkcje
    //Bardzo popularna szutczka
    //wiemy, ze za chwilę xxx zostanie zniszczony
    //za pomocą destrukotra, więc inicjalizujemy
    //this na nullptr i wymieniamy się z xxx
    //delete nullptr jest bezpieczna operacją i nic się nie stanie...
}

void XXX::MojaDrugaNowaFunkcja(XXX &&xxx) { //trza bylo zmienic typ zmiennej przy extrachowaniu tego
    name_ = nullptr;
    swap(name_, xxx.name_);
}

//operator przenoszący:
XXX & XXX::operator=(XXX &&xxx) {
    //jeśli ktoś wpadł na pomsył x = move(x);
    if (this == &xxx) {
        return xxx;
    }
    //zabezpiecza przed x=x jak ktos chce przeniesc ten sam element pod ten sam element to to dziala
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    delete[] name_;
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    name_ = nullptr;
    swap(name_,xxx.name_);
}