#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include <GL/glut.h>
#include "Entity.h"

class DynamicObject;

class GameObject: public Entity{

public:
	GameObject();
	~GameObject();
	
	Vector3 halvies;
	virtual void draw();
	virtual void update(double delta_t);
	void setHalvies(const Vector3 & speed);
	void setHalvies(double x, double y, double z);
	Vector3 getHalvies();
	int colision(DynamicObject* frogp);
};
#endif