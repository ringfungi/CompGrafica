#include "River.h"
#include <GL/GLUT.h>



/*0.55
0.96*/
River::River(){
	this->setHalvies(5.0f, 0.55f, 0.0f);
	this->setPosition(0.0f, 0.9f, 0.0f);
}
River::~River(){}

void River::draw(){
	//RIO
	/*glPushMatrix();
	glColor3f(0.0f, 0.7f, 1.0f);
	glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
	glScalef(4.0f, 2.3f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();*/
    
    glPushMatrix();
    glTranslatef(this->position.getX(), this->position.getY(), this->position.getZ());
    glScalef(6.0f, 1.8f, 0.0f);
    glColor3f(0.0f, 0.7f, 1.0f);
    glutSolidCube(0.8);
    glPopMatrix();
    

}
