//
// Created by Grove on 2017-05-18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <iostream>
#include <complex>
#include <memory>
#include <vector>
using std::cout;
using std::endl;

namespace factoryMethod {

    template<class T>
    T Create() {
        return T();
    }


    class MyType {
    public:
        MyType();

        std::string SayHello();
    };

    template<class TYPE>
    TYPE Sum(TYPE number1,TYPE number2)
    {
        return number1 + number2;
    };

    template <class POINTTYPE>
    auto Value(POINTTYPE pointtype)
    {
        return *pointtype;
    };

    template <class TYPE>
    double Mean(std::vector<TYPE> vec)
    {
        double sum;
        for(auto &n : vec)
        {
            sum += n;
        }
            return sum / vec.size();
    }

    class Logger{
//
//        template<class TYPE>
//                Logger(TYPE t)() : {};
    public:
                        template<class TYPE>
                                Debug(TYPE t)
        {
            return
        }
    private:

    };



}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
