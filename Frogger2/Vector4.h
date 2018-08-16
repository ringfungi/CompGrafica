#ifndef __VECTOR4_H__
#define __VECTOR4_H__
#include "Vector3.h"


class Vector4 : public Vector3
{
private:
	double w;

public:
	Vector4(double x, double y, double z, double w);
	~Vector4();
	Vector4();

	double getW();
	void set(double x, double y, double z, double w);
	Vector4 operator=(const Vector4 & vec);
	Vector4 operator*(double num);
	Vector4 operator+(const Vector4 & vec);
	Vector4 operator-(const Vector4 & vec);
};

#endif