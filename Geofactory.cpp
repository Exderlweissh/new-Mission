#pragma once
#include "Geofactory.h"
static Geometry* makeGeometry(QString myfile) {
	QTextStream ss(&myfile);
	QString item;
	ss >> item;
	if (item == "Point") {
		QString col1, col2, sty1, sty2,x,y,del;
		ss >> col1 >> sty1 >> col2 >> sty2>>del>>x>>y;
        CPoint* P = new CPoint;
		P->setBorderColor(QColor(col1));
		P->setBorderStyle((Qt::PenStyle)sty1.toInt());
		P->setFillColor(QColor(col2));
		P->setFillStyle((Qt::BrushStyle)sty2.toInt());
		Point p = { x.toDouble(), y.toDouble() };
		P->setPoint(p);
		return P;
	}
	else if (item == "Polyline") {
		QString col1, col2, sty1, sty2, x, y, del;
		ss >> col1 >> sty1 >> col2 >> sty2 >> del;
		CPolyline* L = new CPolyline;
		L->setBorderColor(QColor(col1));
		L->setBorderStyle((Qt::PenStyle)sty1.toInt());
		L->setFillColor(QColor(col2));
		L->setFillStyle((Qt::BrushStyle)sty2.toInt());
		vector<Point> ps;
		for (ss >> x >> y >> del; del.isEmpty();) {
			Point p = { x.toDouble(), y.toDouble() };
			ps.push_back(p);
		}
		L->setPoints(ps);
		return L;
	}
	else if (item == "Polygon") {
		QString col1, col2, sty1, sty2, x, y, del;
		ss >> col1 >> sty1 >> col2 >> sty2 >> del;
		CPolygon* G = new CPolygon;
		G->setBorderColor(QColor(col1));
		G->setBorderStyle((Qt::PenStyle)sty1.toInt());
		G->setFillColor(QColor(col2));
		G->setFillStyle((Qt::BrushStyle)sty2.toInt());
		vector<Point> ps;

	}
}