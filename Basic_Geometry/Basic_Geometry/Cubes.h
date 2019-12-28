#pragma once
#include "Color.h"
#include "Shapes.h"
#include "Texture.h"
#include "Vertex.h"
#include <cmath>

#define VERTEXNUMBER 8
#define FACES 6
#define EDGES 12

class Cubes : Shapes
{
private:
	Texture texture[FACES];
	Vertex vertexPoint[VERTEXNUMBER];
	Color faceColor[FACES];
	float length;
	int textureNumber;

public:
	Cubes();
	Cubes(float _x, float _y, float _z);
	Cubes(float _x, float _y, float _z, float _length);
	Cubes(float _x, float _y, float _z, float _length, int _colorNumber);
	Cubes(float _x, float _y, float _z, float _length, int _colorNumber, int _texture);
	Cubes(Cubes& _cube);
	~Cubes();
	void setTexture();
	void setVertexPoint(float x1, float x2, float y1, float y2, float z1, float z2);
	void setFaceColor(int _colorNumber);
	void setFaceColor(float _r, float _g, float _b, int _index);
	void setVertexX(float _position, int _index);
	void setVertexY(float _position, int _index);
	void setVertexZ(float _position, int _index);
	void setLength(float _length);
	void setTextureNumber(int _texture);
	void assignCalcs();
	float getLength();
	int getTextureNumber();
	Vertex getVertexPoint(int _vertexNumber);
	Color getFaceColor(int _index);
	void calculateVertex();
	void drawWire();
	void drawSolid();
	void drawTexture();
	void move(float _x, float _y, float _z);
	void scale(float _factor);
	void rotateX(float _angle);
	void rotateY(float _angle);
	void rotateZ(float _angle);
	void setPerimeter();
	void setArea();
	void setVolume();
};

