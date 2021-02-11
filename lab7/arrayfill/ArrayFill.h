//
// Created by Grove on 2017-04-20.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <stdlib.h>
#include <vector>
#include <time.h>
#include <initializer_list>

namespace arrays {

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };


    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;

    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int value = 0, int step = 1) : value_{value} , step_{step} {}

        virtual int Value(int index) const override;

    private:
        int value_;
        int step_;
    };
    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int value = 1, int parm_b = 0) : value_{value} , parm_b_{parm_b} {}

        virtual int Value(int index) const override;

    private:
        int value_;
        int parm_b_;
    };

//    class RandomFill : public ArrayFill {
//    public:
//        RandomFill(std::initializer_list<std::pair<std::unique_ptr, std::unique_ptr>> nazwa) : {engine_ = nazwa[0], uniform_ = nazwa}
//
//        virtual int Value(int index) const override;
//
//    private:
//        std::default_random_engine engine_;
//        std::uniform_int_distribution uniform_;
//
//    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

}
#endif //JIMP_EXERCISES_ARRAYFILL_H
