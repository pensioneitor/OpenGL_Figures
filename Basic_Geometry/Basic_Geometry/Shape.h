#pragma once
#include "Vertex.h"

class Shape
{
protected:

	Vertex origin;
	int numColor;
	int numVertex;
	double perimeter;
	double area;
	double volume;

public:

	void setOrigin(double _x, double _y, double _z);
	void setNumVertex(int _numVertex);
	Vertex getOrigin();
	int getNumColor();
	int getNumVertex();
	double getVolume();
	~Shapes();
};

