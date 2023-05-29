#pragma once
#include "Geo.h"
class CPolygon :public Geometry
{
public:
    CPolygon();
    // 设置点坐标
    void setPoints(const vector<Point> pos);
    // 获取点坐标
    vector<Point> getPoints() const;
    int getPartNum()const;
    double getArea() override;
    double getPerimeter() override;
    void Build(char* buf) override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private:
    vector<Point> points;  // 点的坐标
    int partnum;
    int* parts;
};

