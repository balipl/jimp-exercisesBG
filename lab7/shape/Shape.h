//
// Created by Grove on 2017-04-27.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H

#include <iostream>
#include <random>
#include <time.h>



class Shape {
public:
    virtual void rysuj() = 0;
};

class Trojkat : public Shape{
public:
    Trojkat();
    Trojkat(double h);
    ~Trojkat();

    virtual void rysuj();

private:
    double h_;
};
class Kwadrat : public Shape{
public:
    Kwadrat();
    Kwadrat(double a);
    ~Kwadrat();
    virtual void rysuj();

private:
    double a_;
};

class Kolo : public Shape{
public:
    Kolo();
    Kolo(double r);
    ~Kolo();

    virtual void rysuj();

private:
    double r_;
};


#endif //JIMP_EXERCISES_SHAPE_H
