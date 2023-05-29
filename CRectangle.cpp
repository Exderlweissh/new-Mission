#include "CRectangle.h"
CRectangle::CRectangle() {
	GeoName = "Rectangle";
}

void CRectangle::settwopoint(Point p1, Point p2) {
	this->P1 = p1;
	this->P2 = p2;
}

Point CRectangle::getP1() {
	return P1;
}

Point CRectangle::getP2() {
	return P2;
}

double CRectangle::getArea() {
	return abs((P1.x - P2.x) * (P1.y - P2.y));
}

double CRectangle::getPerimeter() {
	return 2*(abs(P1.x - P2.x) + abs(P1.y - P2.y));
}

QString CRectangle::ConstuctToMyFile() {
	QString file = GeoName + " " + m_borderColor.name() + " " + QString::number((int)m_borderStyle) + " " + m_fillColor.name() + " " + QString::number((int)m_fillStyle) + " (";
	file = file + "left: " + QString::number(min(P1.x, P2.x)) + " top: " + QString::number(max(P1.y, P2.y)) + " right: " + QString::number(max(P1.x, P2.x)) + " bottom: " + QString::number(min(P1.y, P2.y)) + ")";
	return file;
}

QString CRectangle::wkt() const {
	strstream ss;
	ss << "Rectangle(left: "<< min(P1.x, P2.x)<<" top: "<< max(P1.y, P2.y)<< " right: "<< max(P1.x, P2.x)<< " bottom: "<< min(P1.y, P2.y)<<")";
	return QString::fromStdString(ss.str());
}