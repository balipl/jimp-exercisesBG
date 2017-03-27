//
// Created by ASUSTek on 2017-03-27.
//

#include "Square.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

namespace geometry{

    Point::Point() : x_(0), y_(0) {}

    Point::Point(double x, double y){
        x_ = x;
        y_ = y;
    }
    Point::~Point(){

    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY() , 2));
    }
    void Point::ToSting(std::ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }
    void Point::SetX(double x) {
        x_=x;
    }
    void Point::SetY(double y) {
        y_ = y;
    }

    double Point::GetX() const {
        return x_;
    }
    double Point::GetY() const {
        return y_;
    }


    Square::Square(): a_(0,0), b_(0,0), c_(0,0), d_(0,0){}

    Square::Square(Point a, Point b, Point c, Point d) {
        a_=a;
        b_=b;
        c_=c;
        d_=d;
    }
    Square::~Square() {}
    double Square::Circumference() const {
        double side = a_.Distance(b_);
        if(a_.Distance(b_)!=c_.Distance(d_)) return 0;
        if(b_.Distance(d_)!=a_.Distance(c_)) return 0;

        return 4*side;
    }
    double Square::Area() const {
        if(a_.Distance(b_)!=c_.Distance(d_)) return 0;
        if(b_.Distance(d_)!=a_.Distance(c_)) return 0;

        double side = a_.Distance(b_);
        return side*side;

    }


}
