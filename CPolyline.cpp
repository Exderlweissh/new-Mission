#include "CPolyline.h"
CPolyline::CPolyline() {
	GeoName = "Polyline";
};

void CPolyline::setPoints(const vector<Point> pos) {
	points = pos;
};

vector<Point> CPolyline::getPoints() const {
	return points;
};

int CPolyline::getPointNum()const {
	return pointnum;
}

double CPolyline::getArea() {
	return 0;
}

double CPolyline::getPerimeter() {
	double sum = 0;
	if (points.size() < 2)return sum;
	for (int i = 0; i < points.size()-1;i++) {
		Point p1 = points[i];
		Point p2 = points[i+1];
		sum += points_d(p1, p2);
	}
}

void CPolyline::Build(char* buf) {
	int partNum = *(int*)(buf + 36);
	pointnum = *(int*)(buf + 40);
	Point* p = (Point*)(buf + 44 + 4 * partNum);
	for (int i = 0; i < pointnum; i++)
	{
		points.push_back(p[i]);
	}
}

QString CPolyline::wkt() const {
	strstream ss;
	ss << "LINESTRING(";
	for (int i = 0; i < points.size(); i++)
	{
		ss << points[i].x << " " << points[i].y;
		if (i < points.size() - 1)
			ss << ",";
		else
			ss << ")";
	}
	return QString::fromStdString(ss.str());
}

QString CPolyline::ConstuctToMyFile() {
	QString myfile = GeoName + " " + m_borderColor.name() + +" " + QString::number((int)m_borderStyle) + " " + m_fillColor.name() + " " + QString::number((int)m_fillStyle) + " ( ";
	for (int i=0;i < points.size(); i++)
	{
		myfile += QString::number(points[i].x) + " " + QString::number(points[i].y);
		if (i < points.size() - 1)
			myfile += " , ";
		else
			myfile += " )";
	}
	return myfile;
}