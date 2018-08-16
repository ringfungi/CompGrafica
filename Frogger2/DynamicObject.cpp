#include <stdlib.h>
#include <math.h> 
#include <iostream>
#include "DynamicObject.h"

using namespace std;

DynamicObject::DynamicObject(){}
DynamicObject::~DynamicObject(){}

void DynamicObject::update(double delta_t, double game_speed){

	position += speed*game_speed*delta_t;
}
void DynamicObject::setSpeed(const Vector3 & speed){

	this->speed = speed;
}
void DynamicObject::setSpeed(double x, double y, double z){

	speed.set(x, y, z);
}
Vector3 DynamicObject::getSpeed(){

	return (speed);
}

Vector3 DynamicObject::colisionLimits(double left_limit, double right_limit, double up_limit, double down_limit){

	Vector3 speed_ = getSpeed();
	Vector3 position_ = *(getPosition());
	Vector3 halvies_ = getHalvies();
	Vector3 aux_vec, return_vec;

	return_vec.set(position.getX(), position.getY(), position.getZ());

	if (speed_.getX() < 0){
		if ((position_.getX() - halvies_.getX()) <= left_limit){
			aux_vec.set((-position.getX() - 1.86), 0, 0);
			return_vec += aux_vec;
		}
	}
	if (speed_.getX() > 0){
		if ((position_.getX() + halvies_.getX()) >= right_limit){
			aux_vec.set((-position.getX() + 1.86), 0, 0);
			return_vec += aux_vec;
		}
	}
	if (speed_.getY() < 0){
		if ((position_.getY() - halvies_.getY()) <= down_limit){
			aux_vec.set(0, (-position.getY() - 1.888), 0);
			return_vec += aux_vec;
		}
	}
	if (speed_.getY() > 0){
		if ((position_.getY() + halvies_.getY()) >= up_limit){
			aux_vec.set(0, (-position.getY() + 1.888), 0);
			return_vec += aux_vec;
		}
	}

	return return_vec;
}

int DynamicObject::colisionPastLimits(double left_limit, double right_limit, double up_limit, double down_limit){

	Vector3 speed_ = getSpeed();
	Vector3 position_ = *(getPosition());
	Vector3 halvies_ = getHalvies();

	if (speed_.getX() < 0){
		if ((position_.getX() + halvies_.getX()) <= (left_limit - 0.2)){
			return 1;
		}
	}
	if (speed_.getX() > 0){
		if ((position_.getX() - halvies_.getX()) >= (right_limit + 0.2)){
			return 1;
		}
	}
	if (speed_.getY() < 0){
		if ((position_.getY() - halvies_.getY()) <= down_limit){
			return 1;
		}
	}
	if (speed_.getY() > 0){
		if ((position_.getY() - halvies_.getY()) >= up_limit){
			return 1;
		}
	}
	return 0;
}

void DynamicObject::coordReset(){}