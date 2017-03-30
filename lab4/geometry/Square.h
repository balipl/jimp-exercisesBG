//
// Created by ASUSTek on 2017-03-27.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include <ostream>
#include <cmath>
#include <iostream>

namespace geometry {
    class Point {
    public:
        Point();

        Point(double x, double y);

        ~Point();

        void ToSting(std::ostream *out) const;

        double Distance(const Point &other) const;

        double GetX() const;

        double GetY() const;

        void SetX(double x);

        void SetY(double y);

    private:
        double x_, y_;
    };

    class Square {
    public:
        Square();

        Square(Point a, Point b, Point c, Point d);

        ~Square();

        double Circumference() const;

        double Area() const;

    private:
        Point a_, b_, c_, d_;
    };
}

#endif //JIMP_EXERCISES_SQUARE_H
