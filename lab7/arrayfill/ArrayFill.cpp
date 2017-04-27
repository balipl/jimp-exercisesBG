//
// Created by Grove on 2017-04-20.
//

#include "ArrayFill.h"

namespace arrays{


    int UniformFill::Value(int index) const {
        return value_;
    }
    int IncrementalFill::Value(int index) const {
        return value_ + index * step_;
    }
    int SquaredFill::Value(int index) const {
        return value_ * index * index + parm_b_ ;
    }
//    int RandomFill::Value(int index) const {
//        srand ( time(NULL) );
//        int losowa = rand() % 6;
//        return value_ + losowa ;
//    }

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }
}