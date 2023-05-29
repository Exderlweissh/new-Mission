#include "CPoint.h"
CPoint::CPoint() {
	GeoName = "Point";
};

void CPoint::setPoint(const Point pos) {
	point = pos; 
};

Point CPoint::getPoint() const { 
	return point; 
};

double CPoint::getArea(){
	return 0;
}

double CPoint::getPerimeter() {
	return 0;
}

void CPoint::Build(char* buf){
	Point* pt = (Point*)(buf + 4);
	point = *pt;
}

QString CPoint::wkt() const{
	strstream ss;
	ss << "POINT(";
	ss << point.x << " " << point.y;
	ss << ")";
	return QString::fromStdString(ss.str());
}

QString CPoint::ConstuctToMyFile(){
	return GeoName + " " + m_borderColor.name() + " " + QString::number((int)m_borderStyle) + " " + m_fillColor.name() + " " + QString::number((int)m_fillStyle) + " ( " + QString::number(point.x) + " " + QString::number(point.y) + " )";
}
