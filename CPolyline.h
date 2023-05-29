#pragma once
#include "Geo.h"
class CPolyline :public Geometry
{
public:
    CPolyline();
    // ���õ�����
    void setPoints(const vector<Point> pos);
    // ��ȡ������
    vector<Point> getPoints() const;
    int getPointNum()const;
    double getArea() override;
    double getPerimeter() override;
    void Build(char* buf) override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private:
    vector<Point> points;  // �������
    int pointnum;
};

