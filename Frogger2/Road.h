#ifndef __ROAD_H__
#define __ROAD_H__
#include <GL/glut.h>
#include "StaticObject.h"

class Road:public StaticObject{
public:
	Road();
	~Road();

	void draw();
};

#endif