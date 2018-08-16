#include "Bus.h"

int randGen();

Bus::Bus(){

	this->setHalvies(0.205f, 0.15f, 0.0f);
	this->setSpeed(-0.5, 0, 0);
	this->in_game = 0;
	switch (randGen())
	{
		case 1:
		{
			this->setPosition(2.7f, -0.365f, 0.0f);
			break;
		}
		case 2:
		{
			this->setPosition(2.7f, -0.735f, 0.0f);
			break;
		}
		case 3:
		{
			this->setPosition(2.7f, -1.105, 0.0f);
			break;
		}
		default:
		{
			this->setPosition(2.7f, -1.475f, 0.0f);
			break;
		}
	}

}
Bus::~Bus(){}

void Bus::coordReset(){

	this->setSpeed(-0.5, 0, 0);
	this->in_game = 0;

	switch (randGen())
	{
		case 1:
		{
			this->setPosition(2.7f, -0.365f, 0.0f);
			break;
		}
		case 2:
		{
			this->setPosition(2.7f, -0.735f, 0.0f);
			break;
		}
		case 3:
		{
			this->setPosition(2.7f, -1.110, 0.0f);
			break;
		}
		default:
		{
			this->setPosition(2.7f, -1.475f, 0.0f);
			break;
		}
	}
}


void Bus::draw(){
	//CARRO-2

	glPushMatrix();
	glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
	//RODAS_CIMA
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(-0.07f, 0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.1f, 0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();
	//RODAS_BAIXO
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(-0.07f, -0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.1f, -0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();
	//CORPO

	glPushMatrix();
	glColor3f(1.0f, 0.8f, 0.0f);
	glScalef(1.0f, 0.58f, 1.0f);
	glutSolidCube(0.39);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f, 0.8f, 0.0f);
	glTranslatef(0.02f, 0.0f, 0.0f);
	glScalef(1.4f, 1.0f, 0.5f);
	glutSolidCube(0.25);
	glPopMatrix();
	glPopMatrix();
}

