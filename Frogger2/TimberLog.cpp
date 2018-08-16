#include <stdlib.h>
#include <math.h> 
#include "TimberLog.h"

int logSpawn();
void incCounter();

TimberLog::TimberLog(){

	this->frog_riding = 0;
	this->setHalvies(0.62f, 0.132f, 0.0f);
	this->in_game = 0;

	switch (logSpawn())
	{
		case 1:
		{
			this->setPosition(3.5f, 0.45f, 0.0f);
			this->setSpeed(-0.3, 0, 0);
			break;
		}
		case 2:
		{
			this->setPosition(-3.5f, 0.75f, 0.0f);
			this->setSpeed(0.3, 0, 0);
			break;
		}
		case 3:
		{
			this->setPosition(3.5f, 1.05f, 0.0f);
			this->setSpeed(-0.3, 0, 0);
			break;
		}
		default:
		{
			this->setPosition(-3.5f, 1.35f, 0.0f);
			this->setSpeed(0.3, 0, 0);
			break;
		}
	}

}

TimberLog::~TimberLog(){}

void TimberLog::coordReset(){

	this->frog_riding = 0;
	this->in_game = 0;

	if (position.getY() == 0.45f){
		this->setPosition(3.5f, 0.45f, 0.0f);
		this->setSpeed(-0.3, 0, 0);
		return;
	}
	if (position.getY() == 0.75f){
		this->setPosition(-3.5f, 0.75f, 0.0f);
		this->setSpeed(0.3, 0, 0);
		return;
	}
	if (position.getY() == 1.05f){
		this->setPosition(3.5f, 1.05f, 0.0f);
		this->setSpeed(-0.3, 0, 0);
		return;
	}
	if (position.getY() == 1.35f){
		this->setPosition(-3.5f, 1.35f, 0.0f);
		this->setSpeed(0.3, 0, 0);
		return;
	}

}

void TimberLog::draw(){

	//TRONCO-2
	glPushMatrix();
	glColor3f(0.4f, 0.2f, 0.2f);
	glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
	glScalef(5.0f, 1.0f, 0.1f);
	glutSolidCube(0.25);
	glPopMatrix();
}
