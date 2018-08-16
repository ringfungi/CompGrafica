#ifndef __VECTOR3_H__
#define __VECTOR3_H__
#include <GL/glut.h>

class Vector3{
protected:
	double x;
	double y;
	double z;

public:
    Vector3();
	~Vector3();
	Vector3(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
	double* get();
	void set(double x, double y, double z);
	Vector3 operator=(const Vector3 & vec);
	Vector3 operator*(double num);
	Vector3 operator+(const Vector3 & vec);
	Vector3 operator-(const Vector3 & vec);
	Vector3 operator+=(const Vector3 & vec);
	Vector3 operator-=(const Vector3 & vec);

};
#endif 