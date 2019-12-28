#pragma once

class Texture
{
#define checkImageWidth 64
#define checkImageHeight 64
#define MAXFACES 8

	unsigned char checkImage[checkImageWidth][checkImageHeight][3];

public:
	unsigned int texture;
	char* fileLocation;
	char* fileMultiples[MAXFACES];
	unsigned long sizeX;
	unsigned long sizeY;
	char* data;

public:
	Texture();
	Texture(char* _fileLocation, int _textureNumber);
	Texture(char* _filesLocation[], int _textureNumber);
	void setFileLocation(char* _fileLocation);
	void setFileMultiple(char* _filesLocation[], int _textureNumber);
	void setTextureNumber(int _textureNumber);
	void makeCheckImage(void);
	void loadTexture(void);
	void useTexture(void);
	void useTextureIndex(int _index);
	int ImageLoad(char* _filename);
	void clearTexture(void);
	~Texture();
};

