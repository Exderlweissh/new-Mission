
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

    // 获取和设置边框颜色
    QColor borderColor() const ;
    void setBorderColor(const QColor& color) ;

    // 获取和设置边框样式
    Qt::PenStyle borderStyle() const;
    void setBorderStyle(Qt::PenStyle style) ;

    // 获取和设置填充颜色
    QColor fillColor() const;
    void setFillColor(const QColor& color) ;

    // 获取和设置填充样式
    Qt::BrushStyle fillStyle() const ;
    void setFillStyle(Qt::BrushStyle style) ;

    // 获取唯一标识符
    qint64 id() const ;

    //设置表的唯一标识符
    void setTableIndex(qint64 value);

    //是否被删除
    bool IsDel()const;

    //将图像删除
    void Del();

    //计算两点距离
    double points_d(Point p1, Point p2) {
        return pow((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y), 0.5);
    }
public:
    //外部接口
    virtual QString ConstuctToMyFile() = 0; //将图形转为我们定义的格式
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void Build(char* buf) = 0;
    virtual QString wkt() const = 0;

protected:
    QColor m_borderColor;   // 边框颜色
    Qt::PenStyle m_borderStyle; // 边框样式
    QColor m_fillColor;     // 填充颜色
    Qt::BrushStyle m_fillStyle;  // 填充样式
    qint64 m_id;            // 唯一标识符
    bool isDel; //是否被删除
    QString GeoName;
};
#endif
