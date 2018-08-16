#ifndef __DYNAMICOBJECT_H__
#define __DYNAMICOBJECT_H__
#include <GL/glut.h>
#include "GameObject.h"
#include "Vector3.h"

class DynamicObject:public GameObject{
protected:
	Vector3 speed;
public:
	DynamicObject();
	~DynamicObject();
	void update(double delta_t, double game_speed);
	void setSpeed(const Vector3 & speed);
	void setSpeed(double x, double y, double z);
	Vector3 getSpeed();
	virtual void coordReset();
	Vector3 colisionLimits(double left_limit, double right_limit, double up_limit, double down_limit);
	int colisionPastLimits(double left_limit, double right_limit, double up_limit, double down_limit);
	int frog_riding, in_game;
};
#endif