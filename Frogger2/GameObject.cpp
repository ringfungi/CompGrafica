#include <math.h>
#include "GameObject.h"
#include "DynamicObject.h"

GameObject::GameObject(){}
GameObject::~GameObject(){}

void GameObject::draw(){}
void GameObject::update(double delta_t){}

void GameObject::setHalvies(const Vector3 & speed){

	this->halvies = halvies;
}
void GameObject::setHalvies(double x, double y, double z){

	halvies.set(x, y, z);
}
Vector3 GameObject::getHalvies(){

	return (halvies);
}

int GameObject::colision(DynamicObject* frogp){

	if (fabs((frogp->getPosition()->getX()) - (this->getPosition()->getX())) < (frogp->getHalvies().getX() + this->halvies.getX()) && fabs((frogp->getPosition()->getY()) - (this->getPosition()->getY())) < (frogp->getHalvies().getY() + this->halvies.getY())){
		return 1;
	}
	else
		return 0;
}