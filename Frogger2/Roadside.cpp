#include "Roadside.h"

Roadside::Roadside(){}
Roadside::~Roadside(){}

void Roadside::draw(){

	//BERMA_BAIXO
	glPushMatrix();
	glColor3f(0.5f, 0.3f, 0.2f);
	glTranslatef(0.0f, -1.834f, 0.0f);
	glScalef(6.0f, 0.5f, 0.0f);
	glutSolidCube(0.8);
	glPopMatrix();

	//BERMA_MEIO
	glPushMatrix();
	glColor3f(0.5f, 0.3f, 0.2f);
	glScalef(6.0f, 0.5f, 0.0f);
	glutSolidCube(0.8);
	glPopMatrix();
}
