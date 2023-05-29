#pragma once
#include"Geo.h"
class CPoint : public Geometry
{
public:
    CPoint();
    // 设置点坐标
    void setPoint(const Point pos) ;
    // 获取点坐标
    Point getPoint() const ;
    double getArea() override;
    double getPerimeter() override;
    void Build(char* buf) override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private:
    Point point;  // 点的坐标
};

