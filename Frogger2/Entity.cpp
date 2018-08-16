#include "Entity.h"

Entity::Entity(){}
Entity::~Entity(){}
Vector3* Entity::getPosition(){

	return &position;
}
Vector3* Entity::setPosition(double x, double y, double z){

	position.set(x, y, z);

	return &position;
}
Vector3* Entity::setPosition(const Vector3 & p) {

	this->position = p;
	
	return &position;
}
