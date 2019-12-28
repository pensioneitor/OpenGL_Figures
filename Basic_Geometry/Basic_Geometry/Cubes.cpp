#include "Cubes.h"

Cubes::Cubes() {
	setOriginPoint(0.0, 0.0, 0.0);
	setNumVertex(VERTEXNUMBER);
	setLength(1.0);
	setNumColor(0);
	setTextureNumber(0);
	setTexture();
	calculateVertex();
}

Cubes::Cubes(float _x, float _y, float _z) {
	setOriginPoint(_x, _y, _z);
	setNumVertex(VERTEXNUMBER);
	setLength(1.0);
	setNumColor(0);
	setTextureNumber(0);
	setTexture();
	calculateVertex();
}

Cubes::Cubes(float _x, float _y, float _z, float _length) {
	setOriginPoint(_x, _y, _z);
	setNumVertex(VERTEXNUMBER);
	setLength(_length);
	setNumColor(0);
	setTextureNumber(0);
	setTexture();
	calculateVertex();
}

Cubes::Cubes(float _x, float _y, float _z, float _length, int _colorNumber) {
	setOriginPoint(_x, _y, _z);
	setNumVertex(VERTEXNUMBER);
	setLength(_length);
	setNumColor(_colorNumber);
	setTextureNumber(0);
	setTexture();
	calculateVertex();
}

Cubes::Cubes(float _x, float _y, float _z, float _length, int _colorNumber, int _texture) {
	setOriginPoint(_x, _y, _z);
	setNumVertex(VERTEXNUMBER);
	setLength(_length);
	setNumColor(_colorNumber);
	setTextureNumber(_texture);
	setTexture();
	calculateVertex();
}

Cubes::Cubes(Cubes& _cube) {
	setOriginPoint(_cube.getOriginPoint().getX(), _cube.getOriginPoint().getY(), _cube.getOriginPoint().getZ());
	setNumVertex(VERTEXNUMBER);
	setLength(_cube.getLength());
	setNumColor(_cube.getNumColor());
	setTextureNumber(_cube.getTextureNumber());
	setTexture();
	calculateVertex();
}

Cubes::~Cubes() {
	
}

void Cubes::setTexture() {
	char* files[6];
	files[0] = (char*)"Textures/1.bmp";
	files[1] = (char*)"Textures/2.bmp";
	files[2] = (char*)"Textures/3.bmp";
	files[3] = (char*)"Textures/4.bmp";
	files[4] = (char*)"Textures/5.bmp";
	files[5] = (char*)"Textures/6.bmp";
	texture[0] = Texture(files, 6);
	delete[] files;
}

void Cubes::setVertexPoint(float x1, float x2, float y1, float y2, float z1, float z2) {
	vertexPoint[0].setXYZ(x1, y1, z1);
	vertexPoint[1].setXYZ(x1, y1, z2);
	vertexPoint[2].setXYZ(x1, y2, z2);
	vertexPoint[3].setXYZ(x1, y2, z1);
	vertexPoint[4].setXYZ(x2, y1, z1);
	vertexPoint[5].setXYZ(x2, y1, z2);
	vertexPoint[6].setXYZ(x2, y2, z2);
	vertexPoint[7].setXYZ(x2, y2, z1);
}

void Cubes::setFaceColor(int _colorNumber) {
	numColor = _colorNumber;
	switch (_colorNumber) {
	case 1:
		faceColor[0].setRGB(1.0, 1.0, 0.0);	faceColor[1].setRGB(0.0, 1.0, 1.0);
		faceColor[2].setRGB(1.0, 0.0, 1.0);	faceColor[3].setRGB(1.0, 0.0, 0.0);
		faceColor[4].setRGB(0.0, 1.0, 0.0);	faceColor[5].setRGB(0.0, 0.0, 1.0);
		break;
	case 2:
		faceColor[0].setRGB(1.0, 0.0, 1.0);		faceColor[1].setRGB(1.0, 0.0, 0.0);
		faceColor[2].setRGB(0.0, 0.0, 0.75);	faceColor[3].setRGB(0.0, 1.0, 1.0);
		faceColor[4].setRGB(1.0, 0.75, 0.75);	faceColor[5].setRGB(0.75, 1.0, 1.0);
		break;
	case 3:
		faceColor[0].setRGB(0.5, 0.5, 0.5);		faceColor[1].setRGB(0.9, 0.8, 0.7);
		faceColor[2].setRGB(0.6, 0.5, 0.4);		faceColor[3].setRGB(1.0, 1.0, 0.75);
		faceColor[4].setRGB(0.75, 1.0, 1.0);	faceColor[5].setRGB(1.0, 0.75, 1.0);
		break;
	case 4:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(1.0, 0.0, 0.0); }
		break;
	case 5:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(0.0, 1.0, 0.0); }
		break;
	case 6:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(0.0, 0.0, 1.0); }
		break;
	case 7:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(1.0, 1.0, 0.0); }
		break;
	case 8:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(1.0, 0.0, 1.0); }
		break;
	case 9:
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(0.0, 1.0, 1.0); }
		break;
	default:
		numColor = 0;
		for (int i = 0; i < FACES; i++) { faceColor[i].setRGB(0.0, 0.0, 0.0); }
		break;
	}
}

void Cubes::setFaceColor(float _r, float _g, float _b, int _index) {
	if (_index >= 0 && _index < FACES) {
		faceColor[_index].setRGB(_r, _g, _b);
	}
}

void Cubes::setVertexX(float _position, int _index) {
	vertexPoint[_index].setX(_position);
}

void Cubes::setVertexY(float _position, int _index) {
	vertexPoint[_index].setY(_position);
}

void Cubes::setVertexZ(float _position, int _index) {
	vertexPoint[_index].setZ(_position);
}

void Cubes::setLength(float _length) {
	if (_length > 0) {
		length = _length;
	}
	else {
		length = 1.0;
	}
	assignCalcs();
}

void Cubes::setTextureNumber(int _texture) {
	textureNumber = _texture;
}

void Cubes::assignCalcs() {
	setPerimeter();
	setArea();
	setVolume();
}

float Cubes::getLength() {
	return length;
}

int Cubes::getTextureNumber() {
	return textureNumber;
}

Vertex Cubes::getVertexPoint(int _vertexNumber) {
	if (_vertexNumber >= 0 && _vertexNumber < VERTEXNUMBER) {
		return vertexPoint[_vertexNumber];
	}
}

Color Cubes::getFaceColor(int _index) {
	if (_index >= 0 && _index < VERTEXNUMBER) {
		return faceColor[_index];
	}
}

void Cubes::calculateVertex() {
	float x1 = originPoint.getX() + (length / 2);
	float y1 = originPoint.getY() - (length / 2);
	float z1 = originPoint.getZ() - (length / 2);
	float x2 = x1 - length;
	float y2 = y1 + length;
	float z2 = z1 + length;
	setVertexPoint(x1, x2, y1, y2, z1, z2);
}

void Cubes::drawWire() {

}

void Cubes::drawSolid() {

}

void Cubes::drawTexture() {

}

void Cubes::move(float _x, float _y, float _z) {
	for (size_t i = 0; i < VERTEXNUMBER; i++) {
		setVertexX(originPoint.getX() + _x, i);
		setVertexY(originPoint.getY() + _y, i);
		setVertexZ(originPoint.getZ() + _z, i);
	}
}

void Cubes::scale(float _factor) {
	setLength(_factor * getLength());
	calculateVertex();
}

void Cubes::rotateX(float _angle) {
	_angle = _angle * 3.141592 / 180.0;
	for (size_t i = 0; i < VERTEXNUMBER; i++) {
		float tempy = getVertexPoint(i).getY();
		float pivoty = getOriginPoint().getY();
		float pivotz = getOriginPoint().getZ();
		setVertexY(pivoty + (tempy - pivoty) * cos(_angle) - (getVertexPoint(i).getZ() - pivotz) * sin(_angle), i);
		setVertexZ(pivotz + (tempy - pivoty) * sin(_angle) + (getVertexPoint(i).getZ() - pivotz) * cos(_angle), i);
	}
}

void Cubes::rotateY(float _angle) {
	_angle = _angle * 3.141592 / 180.0;
	for (size_t i = 0; i < 8; i++) {
		double tempz = getVertexPoint(i).getZ();
		double pivotz = getOriginPoint().getZ();
		double pivotx = getOriginPoint().getX();
		setVertexZ(pivotz + (tempz - pivotz) * cos(_angle) - (getVertexPoint(i).getX() - pivotx) * sin(_angle), i);
		setVertexX(pivotx + (tempz - pivotz) * sin(_angle) + (getVertexPoint(i).getX() - pivotx) * cos(_angle), i);
	}
}

void Cubes::rotateZ(float _angle) {
	_angle = _angle * 3.141592 / 180.0;
	for (size_t i = 0; i < VERTEXNUMBER; i++) {
		double tempx = getVertexPoint(i).getX();
		double pivotx = getOriginPoint().getX();
		double pivoty = getOriginPoint().getY();
		setVertexX(pivotx + (tempx - pivotx) * cos(_angle) - (getVertexPoint(i).getY() - pivoty) * sin(_angle), i);
		setVertexY(pivoty + (tempx - pivotx) * sin(_angle) + (getVertexPoint(i).getY() - pivoty) * cos(_angle), i);
	}
}

void Cubes::setPerimeter() {
	perimeter = length * EDGES;
}

void Cubes::setArea() {
	area = length * length * FACES;
}

void Cubes::setVolume() {
	volume = length * length * length;
}