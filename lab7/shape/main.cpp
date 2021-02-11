//
// Created by Grove on 2017-04-27.
//

#include "Shape.h"

int main()
{

    Kwadrat kwadrat(5);
    kwadrat.rysuj();

    Trojkat trojkat(4);
    trojkat.rysuj();

    Kolo kolo(3);
    kolo.rysuj();

    std::srand(time(0));

    std::vector<Shape* > shapes;
    for (int i = 0; i < 10; ++i) {
        int randomized = rand()%3;
        switch (randomized){
            case 0:
                shapes.push_back(new Trojkat(5));
            case 1:
                shapes.push_back(new Kwadrat(5));
            case 2:
                shapes.push_back(new Kolo(3));
            }
    }

    for (auto v : shapes){
        v->rysuj();
        std::cout << std::endl;
    }



}