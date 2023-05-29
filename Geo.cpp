#include "Geo.h"
Geometry::Geometry() {
	isDel = false;
	m_borderColor = Qt::black;
	m_fillColor = Qt::black;
	m_borderStyle = Qt::SolidLine;
	m_fillStyle = Qt::SolidPattern;
}

QColor Geometry::borderColor()const {
	return m_borderColor;
};

void Geometry::setBorderColor(const QColor& color) { 
	this->m_borderColor = color; 
};

Qt::PenStyle Geometry::borderStyle() const {
	return m_borderStyle;
};

void Geometry::setBorderStyle(Qt::PenStyle style) {
	this->m_borderStyle = style; 
};

QColor Geometry::fillColor() const {
	return m_fillColor;
};

void Geometry::setFillColor(const QColor& color) { 
	this->m_fillColor = color; 
};

Qt::BrushStyle Geometry::fillStyle() const { 
	return m_fillStyle; 
};

void Geometry::setFillStyle(Qt::BrushStyle style) { 
	this->m_fillStyle = style;
};

qint64 Geometry::id() const {
	return m_id; 
};

void Geometry::setTableIndex(qint64 value) {
	this->m_id = value;
};

bool Geometry::IsDel()const { 
	return isDel;
};

void Geometry::Del() {
	isDel = !isDel;
}