#include "Riverside.h"

Riverside::Riverside(){}
Riverside::~Riverside(){}

void Riverside::draw(){
	//BERMA_CIMA
	glPushMatrix();
	glColor3f(0.1f, 0.7f, 0.0f);
	glTranslatef(0.0f, 1.8f, 0.0f);
	glScalef(6.0f, 0.5f, 0.0f);
	glutSolidCube(0.8);
	glPopMatrix();
}
