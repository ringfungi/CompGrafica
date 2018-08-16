#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <GL/glut.h>
#include "Vector3.h"

class Entity{
protected: 
	Vector3 position;
public:
	Entity();
	~Entity();

	Vector3* getPosition();
	Vector3* setPosition(double x, double y, double z);
	Vector3* setPosition(const Vector3 & p);


};
#endif