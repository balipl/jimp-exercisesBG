//
// Created by ASUSTek on 2017-03-09.
//

#include "GreatestProduct.h"


int GreatestProduct(const std::vector<int> &numbers, int k){
    int max1=-1;
    int max2=-1;
    for (int v : numbers) {
        if(v>max1){
            max2=max1;
            max1=v;
        }
        else if(v>max2){
            max2 = v;
        }
    }
    return max1*max2;





}

