//
// Created by ASUSTek on 2017-03-30.
//
#include "XXX.h"


int MainCopy() {
    //Konstrukcja obiektu za pomoca domylelnego konstruktora
    //nieciekawe
    XXX old_xxx {};

    //Konstrukcja obiektu na podstawie juz zaincjalizowanego
    XXX new_xxx {old_xxx};

    //znowu nieciekawy konstruktor domyslny...
    XXX another_xxx {};

    //tutaj przypisujemy stan obiektu jednego do drugiego
    //ale obydwa sa juĹĽ zaincjalizowane...
    another_xxx = new_xxx;

    //tutaj konczy sie zakres funkcji main i wszystkie trzy obiekty traca wartosc
    //zostaja wywolane wiec destruktory
}
XXX make_copy(XXX xxx) {
    return xxx;
}

int MainMove() {
    //Konstrukcja obiektu za pomoca domyslnego konstruktora
    //nieciekawe
    XXX old_xxx {};

    //Konstrukcja obiektu na podstawie juz zaincjalizowanego
    //z przeniesieniem old_xxx jest niszczony
    XXX new_xxx {std::move(old_xxx)};

    //znowu nieciekawy konstruktor domyslny...
    XXX another_xxx {};

    //tutaj przypisujemy stan obiektu jednego do drugiego
    //ale obydwa sa juz zaincjalizowane...
    //stan new_xxx teraz bedzie w another_xxx, a sam new_xxx jest niszczony
    another_xxx = std::move(new_xxx);

    //tutaj zostanie wywolany konstruktor kopiujacy (argument wysylany przez wartosc)
    //a nastepnie konstruktor przenoszacy (bo wartosc tymczasowa wytworzona przez funkcja make_copy()
    //i tak zaraz zginie
    XXX one_more = make_copy(another_xxx);
    //tutaj watosc tymczasowa z funkcji make_copy juz jest niszczona i wywolywany jest destruktor

    //...

    //tutaj konczy sie zakres funkcji main i wszystkie trzy obiekty traca waznosci
    //zostaja wywolane wiec destruktory (na wszystkich trzech, ale tylko jeden ma wazny stan)
}
int main()
{
    MainMove();
    MainCopy();
    return 0;
}