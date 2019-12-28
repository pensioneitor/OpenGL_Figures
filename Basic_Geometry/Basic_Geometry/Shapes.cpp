#include "Shapes.h"

void Shapes::setOriginPoint(float _x, float _y, float _z) {
	originPoint.setXYZ(_x, _y, _z);
}

void Shapes::setNumVertex(int _numVertex) {
	if (_numVertex > 0) { numVertex = _numVertex; }
}

void Shapes::setNumColor(int _numColor) {
	if (_numColor >= 0) { numColor = _numColor; }
}

Vertex Shapes::getOriginPoint() {
	return originPoint;
}

int Shapes::getNumVertex() {
	return numVertex;
}

int Shapes::getNumColor() {
	return numColor;
}

float Shapes::getPerimeter() {
	return perimeter;
}

float Shapes::getArea() {
	return area;
}

float Shapes::getVolume() {
	return volume;
}

Shapes::~Shapes() {
}