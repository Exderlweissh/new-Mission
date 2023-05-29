#pragma once
#include"Geo.h"
class CPoint : public Geometry
{
public:
    CPoint();
    // ���õ�����
    void setPoint(const Point pos) ;
    // ��ȡ������
    Point getPoint() const ;
    double getArea() override;
    double getPerimeter() override;
    void Build(char* buf) override;
    QString wkt() const override;
    QString ConstuctToMyFile() override;
private:
    Point point;  // �������
};

