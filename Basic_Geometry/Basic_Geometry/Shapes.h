#pragma once
#include "Vertex.h"

class Shapes
{
protected:
	Vertex originPoint;
	int numVertex;
	int numColor;
	float perimeter;
	float area;
	float volume;

public:
	void setOriginPoint(float _x, float _y, float _z);
	void setNumVertex(int _numVertex);
	void setNumColor(int _numColor);
	virtual void setPerimeter() = 0;
	virtual void setArea() = 0;
	virtual void setVolume() = 0;
	Vertex getOriginPoint();
	int getNumVertex();
	int getNumColor();
	float getPerimeter();
	float getArea();
	float getVolume();
	~Shapes();
};

