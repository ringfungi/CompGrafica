#include "Vector3.h"

Vector3::Vector3(){}
Vector3::Vector3(double x, double y, double z){

	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3(){}

double Vector3::getX(){

	return x;
}
double Vector3::getY(){

	return y;
}
double Vector3::getZ(){

	return z;
}

void Vector3::set(double x, double y, double z){

	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3 Vector3::operator=(const Vector3 & vec){

	x = vec.x;
	y = vec.y;
	z = vec.z;
	return *this;
}
Vector3 Vector3::operator*(double num){

	Vector3 result;
	result.set(x*num, y*num, z*num);

	return result;
}

Vector3 Vector3::operator+=(const Vector3 & vec){

	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;
}

Vector3 Vector3::operator-=(const Vector3 & vec){

	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3 & vec){

	Vector3 result;
	result.x = this->x + vec.x;
	result.y = this->y + vec.y;
	result.z = this->z + vec.z;

	return result;
}
Vector3 Vector3::operator-(const Vector3 & vec){
	
	Vector3 result;
	result.x = this->x - vec.x;
	result.y = this->y - vec.y;
	result.z = this->z - vec.z;

	return result;

}
