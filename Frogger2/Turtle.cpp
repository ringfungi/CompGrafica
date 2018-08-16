#include "Turtle.h"


Turtle::Turtle(){}
Turtle::~Turtle(){}

void Turtle::draw(){
	glPushMatrix();
	glScalef(1.5f, 1.5f, 1.5f);
	//Cabeça
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.12f, 0.0f, 0.0f);
	glutSolidSphere(0.03, 70, 70);
	glPopMatrix();

	//Pata1
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.04f, 0.07f, 0.0f);
	glutSolidCube(0.04);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.09f, 0.085f, 0.0f);
	glScalef(1.7f, 0.93f, 1.0f);
	glutSolidSphere(0.020, 70, 70);
	glPopMatrix();

	//Pata2
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.04f, -0.07f, 0.0f);
	glutSolidCube(0.04);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.09f, -0.085f, 0.0f);
	glScalef(1.7f, 0.93f, 1.0f);
	glutSolidSphere(0.020, 70, 70);
	glPopMatrix();

	//Pata3
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.04f, -0.07f, 0.0f);
	glutSolidCube(0.04);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.09f, -0.085f, 0.0f);
	glScalef(1.7f, 0.93f, 1.0f);
	glutSolidSphere(0.020, 70, 70);
	glPopMatrix();

	//Pata4
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.04f, 0.07f, 0.0f);
	glutSolidCube(0.04);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(-0.09f, 0.085f, 0.0f);
	glScalef(1.7f, 0.93f, 1.0f);
	glutSolidSphere(0.020, 70, 70);
	glPopMatrix();
	//Rabo
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.0f);
	glTranslatef(0.12f, 0.0f, 0.0f);
	glScalef(1.8f, 0.9f, 1.0f);
	glutSolidCube(0.03);
	glPopMatrix();
	//Corpo
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glScalef(1.0f, 0.7f, 1.0f);
	glutSolidSphere(0.1, 70, 70);
	glPopMatrix();

	glPopMatrix();



}