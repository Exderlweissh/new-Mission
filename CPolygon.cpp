#include "CPolygon.h"
CPolygon::CPolygon() {
	GeoName = "Polygon";
}

void CPolygon::setPoints(const vector<Point> pos) {
	this->points = points;
}

vector<Point> CPolygon::getPoints() const {
	return points;
}

int CPolygon::getPartNum()const {
	return partnum;
}

double CPolygon::getArea() {
	double area = 0;
	if (points.size() < 3)return area;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        area += points_d(points[i], points[j]);
    }
    area /= 2.0;
    return abs(area); //返回多边形面积
}

double CPolygon::getPerimeter() {
    double length = 0;
    if (points.size() < 3)return length;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        length += points_d(points[i], points[j]);
    }

    return length; //返回多边形周长
}

void CPolygon::Build(char* buf) {
    partnum = *(int*)(buf + 36);
    int Pointsnum = *(int*)(buf + 40);
    parts = (int*)(buf + 44);
    Point* p = (Point*)(buf + 44 + 4 * partnum);
    for(int i = 0; i < Pointsnum; i++)
    {
        points.push_back(p[i]);
    }
}

QString CPolygon::wkt() const {
    strstream ss;
    ss << setiosflags(ios_base::fixed);
    ss << "POLYGON(";
    int pointIndex = 0;
    for (int i = 0; i < partnum; i++)
    {
        ss << "(";
        for (int j = 0; j < parts[i]; j++)
        {
            ss << setprecision(10) << points[pointIndex].x << " " << setprecision(10) << points[pointIndex].y;
            if (j < parts[i] - 1)
                ss << ",";
            else
                ss << ")";
        }
        if (i < partnum - 1)
            ss << ",";
        else
            ss << ")";
    }
    return QString::fromStdString(ss.str());
}

QString CPolygon::ConstuctToMyFile() {
    QString file = GeoName + " " + m_borderColor.name() + " " + QString::number((int)m_borderStyle) + " " + m_fillColor.name() + " " + QString::number((int)m_fillStyle)+ " (";
    for (Point point : points)
    {
        file = file + QString::number(point.x) + " " + QString::number(point.y) + ",";
    }
    file.chop(1);
    file += ")";
    return file;
}