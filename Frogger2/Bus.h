#ifndef __BUS_H__
#define __BUS_H__
#include <GL/glut.h>
#include "DynamicObject.h"

class Bus:public DynamicObject{
public:
	Bus();
	~Bus();
	void coordReset();
	void draw();
};

#endif