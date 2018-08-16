#ifndef __CAR_H__
#define __CAR_H__
#include <GL/glut.h>
#include "DynamicObject.h"

class Car:public DynamicObject{
public:
	Car();
	~Car();
	void coordReset();
	void draw();
};

#endif