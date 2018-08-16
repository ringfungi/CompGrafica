#include "Vector4.h"

Vector4::Vector4(double x, double y, double z, double w){

	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Vector4::~Vector4(){}
Vector4::Vector4(){}

double Vector4::getW(){
	return w;
}
void Vector4::set(double x, double y, double z, double w){

	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}
Vector4 Vector4::operator=(const Vector4 & vec){

	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
	return *this;
}
Vector4 Vector4::operator*(double num){

	Vector4 result;
	result.set(x*num, y*num, z*num, w*num);

	return result;
}
Vector4 Vector4::operator+(const Vector4 & vec){

	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;

	return *this;
}
Vector4 Vector4::operator-(const Vector4 & vec){

	Vector4 result;
	result.x = this->x - vec.x;
	result.y = this->y - vec.y;
	result.z = this->z - vec.z;
	result.w = this->w - vec.w;

	return result;
}
