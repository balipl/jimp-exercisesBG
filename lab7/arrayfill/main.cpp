//
// Created by Grove on 2017-04-20.
//

#include "ArrayFill.h"

int main(){
    std::vector<int> vs;
    arrays::FillArray(1024, arrays::UniformFill {77}, &vs);

}