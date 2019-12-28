#pragma once

class Vertex
{
	private:
		float x;
		float y;
		float z;

	public:

		Vertex();
		Vertex(float _x, float _y);
		Vertex(float _x, float _y, float _z);
		~Vertex();

		float getX();
		float getY();
		float getZ();
		void setX(float _x);
		void setY(float _y);
		void setZ(float _z);
		void setXY(float _x, float _y);
		void setXYZ(float _x, float _y, float _z);
		void moveVertexX(float _x);
		void moveVertexY(float _y);
		void moveVertexZ(float _z);
		void moveVertex2d(float _x, float _y);
		void moveVertex3d(float _x, float _y, float _z);
		void moveVertexBase2d(float _basex, float _basey, float _x, float _y);
		void moveVertexBase3d(float  _basex, float _basey, float _basez, float _x, float _y, float _z);
		void scaleVertex2d(float _factor);
		void scaleVertex3d(float _factor);
		void scaleVertexBase2d(float _factor, float _x, float _y);
		void scaleVertexBase3d(float _factor, float _x, float _y, float _z);
		void rotateVertexX(float _theta, float _pivoty, float _pivotz);
		void rotateVertexY(float _theta, float _pivotx, float _pivotz);
		void rotateVertexZ(float _theta, float _pivotx, float _pivoty);
		void rotateVertex2d(float _theta);
		void rotateVertex3d(float _theta);
		void rotateVertexBase2d(float _pivotx, float _pivoty, float _theta);
		void rotateVertexBase3d(float _pivotx, float _pivoty, float _pivotz, float _theta);
};
