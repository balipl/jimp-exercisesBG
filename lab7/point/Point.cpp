//
// Created by Grove on 2017-04-27.
//

#include <cmath>
#include <ostream>
#include <iostream>
#include "Point.h"

using std::ostream;
using ::std::endl;
using ::std::cout;
using ::std::pow;
using ::std::sqrt;

Point::Point() : x_(0), y_(0) {
    cout << "Konstruktor bezparametrowy Point" << endl;
}

Point::Point(double x, double y) {
    cout << "Konstruktor parametrowy Point" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    cout << "Destruktor Point" << endl;
}

double Point::Distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}

//point3D

Point3D::Point3D() : Point(), z_(0) {
    cout << "Konstruktor bezparametrowy Point 3D" << endl;
}

Point3D::Point3D(double x, double y, double z) : Point(x, y) {
    cout << "Konstruktor parametrowy Point3D" << endl;
    z_ = z;
}

Point3D::~Point3D() {
    cout << "Destruktor Point 3D!" << endl;
}

double Point3D::GetZ() const {
    return z_;
}

void Point3D::SetZ(double z) {
    z_ = z;
}

double Point3D::Distance(const Point3D &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2) + pow(GetZ() - other.GetZ(), 2));
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" + std::to_string(point.GetX()) + "," + std::to_string(point.GetY()) + ")";
    return out;
}