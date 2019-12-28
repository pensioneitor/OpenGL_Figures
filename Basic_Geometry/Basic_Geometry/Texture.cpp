#include "Texture.h"
#include <iostream>
//#include <gl\GLU.h> add gl/glut.h

Texture::Texture() {
	fileLocation = (char*)"";
}

Texture::Texture(char* _fileLocation, int _textureNumber) {
	fileLocation = _fileLocation;
	setTextureNumber(_textureNumber);
}

Texture::Texture(char* _filesLocation[], int _textureNumber) {
	setTextureNumber(_textureNumber);
	for (size_t i = 0; i < texture; i++) {
		fileMultiples[i] = _filesLocation[i];
	}
}

void Texture::setFileLocation(char* _fileLocation) {
	fileLocation = _fileLocation;
}

void Texture::setFileMultiple(char* _filesLocation[], int _textureNumber) {
	setTextureNumber(_textureNumber);
	for (size_t i = 0; i < texture; i++) {
		fileMultiples[i] = _filesLocation[i];
	}
}

void Texture::setTextureNumber(int _textureNumber) {
	texture = _textureNumber;
}

void Texture::makeCheckImage() {

	int i, j, c;
	for (i = 0; i < checkImageWidth; i++) {
		for (j = 0; j < checkImageHeight; j++) {
			c = ((((i & 0x8) == 0) ^ ((j & 0x8) == 0))) * 255;
			checkImage[i][j][0] = (unsigned char)c;
			checkImage[i][j][1] = (unsigned char)c;
			checkImage[i][j][2] = (unsigned char)c;
		}
	}
}

void Texture::loadTexture() {
	if (fileLocation == NULL) {
		for (size_t i = 0; i < texture; i++) {
			if ((!ImageLoad(fileMultiples[i]))) {
				system("PAUSE");
				exit(1);
			}
			makeCheckImage();
		}
	}
	else {
		if ((!ImageLoad(fileLocation))) {
			system("PAUSE");
			exit(1);
		}
		makeCheckImage();
	}
}

void Texture::useTexture() {
	/*glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0,
		GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);*/
}

void Texture::useTextureIndex(int _index) {
	/*glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (size_t i = 0; i < texture; i++) {
		glBindTexture(GL_TEXTURE_2D, i);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //scale linearly when image bigger than texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //scale linearly when image smalled than texture
		glTexImage2D(GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);*/
}

int Texture::ImageLoad(char* _filename) {
	FILE* file;
	unsigned long size; // size of the image in bytes.
	unsigned long i; // standard counter.
	unsigned short int planes; // number of planes in image (must be 1)
	unsigned short int bpp; // number of bits per pixel (must be 24)
	char temp; // temporary color storage for bgr-rgb conversion.
	if (fopen_s(&file, _filename, "rb")) {
		std::cout << "File Not Found: " << _filename << std::endl;
		return 0;
	}
	
	/*if ((file = fopen(filename, "rb")) == NULL) {
		std::cout << "File Not Found: " << filename << std::endl;
		return 0;
	}*/

	fseek(file, 18, SEEK_CUR);

	if ((i = fread(&sizeX, 4, 1, file)) != 1) {
		std::cout << "Error reading width from " << _filename << std::endl;
		return 0;
	}

	if ((i = fread(&sizeY, 4, 1, file)) != 1) {
		std::cout << "Error reading height from " << _filename << std::endl;
		return 0;
	}

	size = sizeX * sizeY * 3;

	if ((fread(&planes, 2, 1, file)) != 1) {
		std::cout << "Error reading planes from " << _filename << std::endl;
		return 0;
	}

	if (planes != 1) {
		std::cout << "Planes from " << _filename << " is not 1: " << planes << std::endl;
		return 0;
	}

	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		std::cout << "Error reading bpp from " << _filename << std::endl;
		return 0;
	}

	if (bpp != 24) {
		std::cout << "Bpp from %s is not 24: " << _filename << std::endl;
		return 0;
	}

	fseek(file, 24, SEEK_CUR);

	data = (char*)malloc(size);

	if (data == NULL) {
		std::cout << "Error allocating memory for color-corrected image data" << std::endl;
		return 0;
	}

	if ((i = fread(data, size, 1, file)) != 1) {
		std::cout << "Error reading image data from " << _filename << std::endl;
		return 0;
	}

	for (i = 0; i < size; i += 3) { // reverse all of the colors. (bgr -> rgb)
		temp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = temp;
	}
	return 1;
}

void Texture::clearTexture() {
	//glDeleteTextures(1, &texture);
	fileLocation = (char*)"";
}

Texture::~Texture() {
	clearTexture();
}