#include "Road.h"

Road::Road(){}
Road::~Road(){}

void Road::draw(){
	//ESTRADA
    
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -1.0f, 0.0f);
	glScalef(3.0f, 0.6f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidCube(2);
	glPopMatrix();

	//LINHAS_ESTRADA

	//FAIXA-1
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.7f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-0.7f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.4f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-1.4f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(2.1f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-2.1f, -0.55f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	//FAIXA-3
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.7f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-0.7f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.4f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-1.4f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(2.1f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-2.1f, -0.92f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	//FAIXA-4
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.7f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-0.7f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(1.4f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-1.4f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(2.1f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-2.1f, -1.29f, 0.0f);
	glScalef(8.0f, 1.0f, 0.1f);
	glutSolidCube(0.04);
	glPopMatrix();


	glPopMatrix();
}
