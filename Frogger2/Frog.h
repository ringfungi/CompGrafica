#ifndef __FROG_H__
#define __FROG_H__
#include <GL/glut.h>
#include "DynamicObject.h"
#include "Vector3.h"

class Frog:public DynamicObject{
public:
	Frog();
	~Frog();
	void coordReset();
	void draw();
};

#endif