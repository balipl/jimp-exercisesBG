//
// Created by ASUSTek on 2017-03-09.
//

#include "GreatestProduct.h"
using namespace std;

int GreatestProduct(const vector<int> &numbers, int k){
    vector<int> max_p;
    vector<int> max_m;
    int maximum_m = 1;
    int maximum_p = -1;

    for (auto n : numbers) {
        if(n > maximum_p)
            max_p.push_back(n);
        if(n<maximum_m)
            max_m.push_back(n);
    }

    return 0;





}

