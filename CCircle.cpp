#include "CCircle.h"
CCircle::CCircle() {
	GeoName = "Circle";
}

void CCircle::setcirclepoint(Point centerP, Point borderP) {
	this->CenterPoint = centerP;
	this->BorderPiont = borderP;
	radius = getRadius();
}

Point CCircle::getCenter()const {
	return CenterPoint;
}

double CCircle::getRadius() { 
	return points_d(CenterPoint, BorderPiont);
}

double CCircle::getArea() {
	return 3.14159265358979323846 * radius * radius;
}

double CCircle::getPerimeter() {
	return 2 * 3.14159265358979323846 * radius;
}

QString CCircle::wkt() const {
	strstream ss;
	ss << "Circle(center: " << CenterPoint.x << " " << CenterPoint.y << " radius: " << radius << ")";
	return QString::fromStdString(ss.str());
}

QString CCircle::ConstuctToMyFile() {
	QString file = GeoName + " " + m_borderColor.name() + " " + QString::number((int)m_borderStyle) + " " + m_fillColor.name() + " " + QString::number((int)m_fillStyle) + " (";
	file = file + "center: " + QString::number(CenterPoint.x) + " " + QString::number(CenterPoint.y) + " radius: " + QString::number(radius)+ ")";
	return file;
}