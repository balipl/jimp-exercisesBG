//
// Created by ASUSTek on 2017-03-09.
//

#include "MultiplicationTable.h"

using std::cout;
using std::endl;

void Table(int tab[][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            cout << tab[x][y] << " ";
        }
        cout << endl;
    }
}

void MultiplicationTable(int tab[][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            tab[x][y] = (x + 1) * (y + 1);
        }
    }
}