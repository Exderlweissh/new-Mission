#pragma once
#include "Geo.h"
class CPolygon :public Geometry
{
public:
    CPolygon();
    // ���õ�����
    void setPoints(const vector<Point> pos);
    // ��ȡ������
    vector<Point> getPoints() const;
    int getPartNum()const;
    double getArea() override;
    double getPerimeter() override;
    void Build(char* buf) override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private:
    vector<Point> points;  // �������
    int partnum;
    int* parts;
};

