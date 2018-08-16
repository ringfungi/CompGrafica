#ifndef __TIMBERLOG_H__
#define __TIMBERLOG_H__
#include <GL/glut.h>
#include "DynamicObject.h"

class TimberLog:public DynamicObject{
public:
	TimberLog();
	~TimberLog();
	void coordReset();
	void draw();
};

#endif