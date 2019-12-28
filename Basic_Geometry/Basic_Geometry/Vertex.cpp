#include "Vertex.h"
#include <cmath>

Vertex::Vertex() {
	setXYZ(0.0, 0.0, 0.0);
}

Vertex::Vertex(float _x, float _y) {
	setXYZ(_x, _y, 0.0);
}

Vertex::Vertex(float _x, float _y, float _z) {
	setXYZ(_x, _y, _z);
}

Vertex::~Vertex() {
}

float Vertex::getX() {
	return x;
}

float Vertex::getY() {
	return y;
}

float Vertex::getZ() {
	return z;
}

void Vertex::setX(float _x) {
	x = _x;
}

void Vertex::setY(float _y) {
	y = _y;
}

void Vertex::setZ(float _z) {
	z = _z;
}

void Vertex::setXY(float _x, float _y) {
	setX(_x);
	setY(_y);
}

void Vertex::setXYZ(float _x, float _y, float _z) {
	setX(_x);
	setY(_y);
	setZ(_z);
}

void Vertex::moveVertexX(float _x) {
	setX(getX() + _x);
}

void Vertex::moveVertexY(float _y) {
	setY(getY() + _y);
}

void Vertex::moveVertexZ(float _z) {
	setZ(getZ() + _z);
}

void Vertex::moveVertex2d(float _x, float _y) {
	moveVertexX(_x);
	moveVertexY(_y);
}

void Vertex::moveVertex3d(float _x, float _y, float _z) {
	moveVertexX(_x);
	moveVertexY(_y);
	moveVertexZ(_z);
}

void Vertex::moveVertexBase2d(float _basex, float _basey, float _x, float _y) {
	moveVertex2d(_x + _basex, _y + _basey);
}

void Vertex::moveVertexBase3d(float  _basex, float _basey, float _basez, float _x, float _y, float _z) {
	moveVertex3d(_x + _basex, _y + _basey, _z + _basez);
}

void Vertex::scaleVertex2d(float _factor) {
	setXY(getX() * _factor, getY() * _factor);
}

void Vertex::scaleVertex3d(float _factor) {
	setXYZ(getX() * _factor, getY() * _factor, getZ() * _factor);
}

void Vertex::scaleVertexBase2d(float _factor, float _x, float _y) {
	setXY(_x * _factor, _y * _factor);
}

void Vertex::scaleVertexBase3d(float _factor, float _x, float _y, float _z) {
	setXYZ(_x * _factor, _y * _factor, _z * _factor);
}

void Vertex::rotateVertexX(float _theta, float _pivoty, float _pivotz) {
	float temp_y = getY();
	_theta = _theta * 3.141592 / 180.0;
	setY(_pivoty + (temp_y - _pivoty) * cos(_theta) - (getZ() - _pivotz) * sin(_theta));
	setZ(_pivotz + (temp_y - _pivoty) * sin(_theta) + (getZ() - _pivotz) * cos(_theta));
}

void Vertex::rotateVertexY(float _theta, float _pivotx, float _pivotz) {
	float temp_z = getZ();
	_theta = _theta * 3.141592 / 180.0;
	setZ(_pivotz + (temp_z - _pivotz) * cos(_theta) - (getX() - _pivotx) * sin(_theta));
	setX(_pivotx + (temp_z - _pivotz) * sin(_theta) + (getX() - _pivotx) * cos(_theta));
}

void Vertex::rotateVertexZ(float _theta, float _pivotx, float _pivoty) {
	float temp_x = getX();
	_theta = _theta * 3.141592 / 180.0;
	setX(_pivotx + (temp_x - _pivotx) * cos(_theta) - (getY() - _pivoty) * sin(_theta));
	setY(_pivoty + (temp_x - _pivotx) * sin(_theta) + (getY() - _pivoty) * cos(_theta));
}

void Vertex::rotateVertex2d(float _theta) {
	float temp_x = getX(), temp_y = getY();
	_theta = _theta * 3.141592 / 180.0;
	x = temp_x * cos(_theta) - temp_y * sin(_theta);
	y = temp_x * sin(_theta) + temp_y * cos(_theta);
}

void Vertex::rotateVertex3d(float _theta) {
	rotateVertexX(_theta, 0.0, 0.0);
	rotateVertexY(_theta, 0.0, 0.0);
	rotateVertexZ(_theta, 0.0, 0.0);
}

void Vertex::rotateVertexBase2d(float _pivotx, float _pivoty, float _theta) {
	float temp_x = getX(), temp_y = getY();
	_theta = _theta * 3.141592 / 180.0;
	x = _pivotx + (temp_x - _pivotx) * cos(_theta) - (temp_y - _pivoty) * sin(_theta);
	y = _pivoty + (temp_x - _pivotx) * sin(_theta) + (temp_y - _pivoty) * cos(_theta);
}

void Vertex::rotateVertexBase3d(float _pivotx, float _pivoty, float _pivotz, float _theta) {
	rotateVertexX(_theta, _pivoty, _pivotz);
	rotateVertexY(_theta, _pivotx, _pivotz);
	rotateVertexZ(_theta, _pivotx, _pivoty);
}