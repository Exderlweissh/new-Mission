#pragma once
#include"Geo.h"
#include"CCircle.h"
#include"CPoint.h"
#include"CPolyline.h"
#include"CPolygon.h"
#include"CRectangle.h"
#include"CSector.h"
#include"CPolygon.h"
class Geofactory
{
	static Geometry* makeShape(QString myfile);
};

