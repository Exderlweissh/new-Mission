#pragma once
#include "Geo.h"
class CCircle :
    public Geometry
{
public:
    CCircle();
    void setcirclepoint(Point centerP, Point borderP);
    Point getCenter()const;
    double getRadius();
    double getArea() override;
    double getPerimeter() override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private: 
    Point CenterPoint, BorderPiont;
    double radius;
};

