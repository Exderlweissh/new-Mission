
#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication.h"
#include <QGraphicsItem>
#include<Qvariant>
#include<vector>
#include<string>
#include <strstream>
#include<cmath>
#include <iomanip>
#include<QString>
#include<QTextStream>
#ifndef GEO_H
#define GEO_H
using namespace std;

struct BBox
{
    double Xmin;
    double Ymin;
    double Xmax;
    double Ymax;
};

struct Point
{
    double x;
    double y;
};

class Geometry 
{
public:
    Geometry();

    // ��ȡ�����ñ߿���ɫ
    QColor borderColor() const ;
    void setBorderColor(const QColor& color) ;

    // ��ȡ�����ñ߿���ʽ
    Qt::PenStyle borderStyle() const;
    void setBorderStyle(Qt::PenStyle style) ;

    // ��ȡ�����������ɫ
    QColor fillColor() const;
    void setFillColor(const QColor& color) ;

    // ��ȡ�����������ʽ
    Qt::BrushStyle fillStyle() const ;
    void setFillStyle(Qt::BrushStyle style) ;

    // ��ȡΨһ��ʶ��
    qint64 id() const ;

    //���ñ��Ψһ��ʶ��
    void setTableIndex(qint64 value);

    //�Ƿ�ɾ��
    bool IsDel()const;

    //��ͼ��ɾ��
    void Del();

    //�����������
    double points_d(Point p1, Point p2) {
        return pow((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y), 0.5);
    }
public:
    //�ⲿ�ӿ�
    virtual QString ConstuctToMyFile() = 0; //��ͼ��תΪ���Ƕ���ĸ�ʽ
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void Build(char* buf) = 0;
    virtual QString wkt() const = 0;

protected:
    QColor m_borderColor;   // �߿���ɫ
    Qt::PenStyle m_borderStyle; // �߿���ʽ
    QColor m_fillColor;     // �����ɫ
    Qt::BrushStyle m_fillStyle;  // �����ʽ
    qint64 m_id;            // Ψһ��ʶ��
    bool isDel; //�Ƿ�ɾ��
    QString GeoName;
};
#endif
