#pragma once
#include "Geo.h"
class CRectangle :public Geometry
{
public:
    CRectangle();
    void settwopoint(Point p1, Point p2);
    Point getP1();
    Point getP2();
public:
    double getArea() override;
    double getPerimeter() override;
    QString ConstuctToMyFile() override;
    QString wkt() const override;
private:
    Point P1, P2;
};

