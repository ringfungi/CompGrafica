#ifndef __GAME_LIMITS_H__
#define __GAME_LIMITS_H__
#include <GLUT/glut.h>
#include "StaticObject.h"

class GameLimits : public StaticObject{
public:
	
	GameLimits();
	~GameLimits();
	void draw();
};

#endif