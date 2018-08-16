#include "GameLimits.h"

GameLimits::GameLimits(){
	
}
GameLimits::~GameLimits(){}

void GameLimits::draw(){
    return;
	glPushMatrix();
	glColor3f(0.5f, 1.0f, 1.0f);
	glTranslatef(0.0f, -2.5f, 0.0f);
	glScalef(4.0f, 0.1f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 1.0f, 1.0f);
	glTranslatef(0.0f, 2.5f, 0.0f);
	glScalef(4.0f, 0.1f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 1.0f, 1.0f);
	glTranslatef(-2.5f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glScalef(4.0f, 0.1f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 1.0f, 1.0f);
	glTranslatef(2.5f, 0.0f, 0.0f);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glScalef(4.0f, 0.1f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

}