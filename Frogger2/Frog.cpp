#include <stdlib.h>
#include <iostream>
#include "Frog.h"

using namespace std;

Frog::Frog(){

	this->setHalvies(0.12f, 0.1f, 0.0f);
	this->setSpeed(0,0,0);
	this->setPosition(0,-1.80,0.0);
}

Frog::~Frog(){}

void Frog::coordReset(){

	this->setPosition(0, -1.80, 0.0);
}


void Frog::draw(){

	//SAPO
	
	glPushMatrix();
	glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
	//CORPO
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glutSolidSphere(0.1, 70, 70);

	//PATA_DIREITA_CIMA
	glPushMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.1f, 0.02f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.11f, 0.05f, 0.1f);
	glScalef(2.0f, 4.0f, 0.0f);
	glutSolidCube(0.02);
	glPopMatrix();
	glPopMatrix();

	//PATA_ESQUERDA_CIMA
	glPushMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.1f, 0.02f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.11f, 0.05f, 0.1f);
	glScalef(2.0f, 4.0f, 0.0f);
	glutSolidCube(0.02);
	glPopMatrix();
	glPopMatrix();
	//PATA_DIREITA_BAIXO
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.1f, -0.02f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.11f, -0.05f, 0.1f);
	glScalef(2.0f, 4.0f, 0.0f);
	glutSolidCube(0.02);
	glPopMatrix();

	//PATA_ESQUERDA_BAIXO
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.1f, -0.02f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.11f, -0.05f, 0.1f);
	glScalef(2.0f, 4.0f, 5.0f);
	glutSolidCube(0.02);
	glPopMatrix();

	//OLHOS_SAPO
	glPushMatrix();
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.04f, 0.07f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(-0.04f, 0.07f, 0.1f);
	glScalef(1.0f, 2.0f, 0.0f);
	glutSolidCube(0.01);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}