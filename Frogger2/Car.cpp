#include <stdlib.h>
#include <iostream>
#include <math.h> 
#include "Car.h"

int randGen();

Car::Car(){

	this->setSpeed(-0.5, 0, 0);
	this->in_game = 0;
	this->setHalvies(0.186f, 0.15f, 0.0f);
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
Car::~Car(){}

void Car::coordReset(){

	this->in_game = 0;
	this->setSpeed(-0.5, 0, 0);

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

void Car::draw(){

	//CARRO-1
	glPushMatrix();
	glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
	//RODAS_CIMA
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(-0.08f, 0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.08f, 0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();
	//RODAS_BAIXO
	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(-0.08f, -0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.7f, 0.7f, 0.7f);
	glTranslatef(0.08f, -0.125f, 0.0f);
	glScalef(1.5f, 1.0f, 1.0f);
	glutSolidCube(0.05);
	glPopMatrix();

	//CORPO
	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.0f);
	glScalef(1.4f, 1.0f, 1.0f);
	glutSolidCube(0.25);
	glPopMatrix();

	glColor3f(0.8f, 0.0f, 0.0f);
	glutSolidCube(0.15);
	glPopMatrix();

}
