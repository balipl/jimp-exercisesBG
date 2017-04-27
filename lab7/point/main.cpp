//
// Created by Grove on 2017-04-27.
//

#include "Point.h"

#include <iostream>

int main() {
    Point punkt2d(1, 2);
    Point3D punkt3d(2, 4, 5);

    /* przy tworzeniu punktu2d wywoluje sie konkstuktor Point, a przy dekonstruowaniu dekonstruktor ~Point
     * przytworzeniu punktu3d wywyołuje sie najpierw konstruktor klasy bazowej Point, a potem konstruktor Point3D,
     * a przy dekonstrukcji punktu3d najpierw wywołuje sie dekonstruktor Point3D, a potem Point (klasy są jak cebula) */


    std::cout << punkt2d.Distance(punkt3d);

    /*definicja w klasie punkt2 uzywa tylko punktow x i y, a wiec z punktu3d zostania pobrane tylko wartosci x i y,
     * i zostanie policzona odleglosc tak jakby punkt3d byl punktem 2d. */


    std::cout << punkt3d << std::endl;

    /* po uzyciu przeciazonego operatora punktu2d na punkcie 3d, zostaja wypisane tylko wspolrzedne x,y pomijajac z,
     * bo przeciazenie operatora jest zdefiniowane tylko dla point*/
}