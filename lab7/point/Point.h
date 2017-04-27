//
// Created by Grove on 2017-04-27.
//

#ifndef PROJECTNAME_PATH_POINT_H_
#define PROJECTNAME_PATH_POINT_H_

#include <ostream>

class Point {
public:
    //Konstruktor bezparametrowy
    Point();

    //Konstruktor parametrowy
    Point(double x, double y);

    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point();

    //Metody nie modyfikujące stanu obiektu (const na końcu metody)
    //nie mogą zmodyfikować tego obiektu.
    void ToString(std::ostream *out) const;

    double Distance(const Point &other) const;


    //metody akcesorów są publiczne i tylko w przy ich pomocy
    //można się dostać z zewnątrz do pól klasy
    double GetX() const;

    double GetY() const;

    //metody seterów pozwalające zmienić stan obiektu
    //po jego zainicjalizowaniu
    void SetX(double x);

    void SetY(double y);

private:
    double x_, y_;
};


class Point3D : public Point {
public:
    //Konstruktor bezparametrowy
    Point3D();

    //Konstruktor parametrowy
    Point3D(double x, double y, double z);

    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point3D();

    double Distance(const Point3D &other) const;

    double GetZ() const;

    void SetZ(double z);

private:
    double z_;
};


std::ostream &operator<<(std::ostream &out, const Point &point);

#endif  // PROJECTNAME_PATH_POINT_H_