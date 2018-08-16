#include "LightSource.h"
#include <GL/glut.h>

LightSource::LightSource(GLenum number){

	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

	if (number == 0){
		GLfloat position[] = { 0.5, 0.5, 1.0, 0.0 };
		cut_off = 45.0;
		exponent = 2.0;

		glEnable(GL_LIGHTING);

		glDisable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cut_off);
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, exponent);

		GLfloat a = 0.80, b = 0.0, c = 0.5;
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, a);
		glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, b);
		glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, c);

		glEnable(GL_LIGHT0);

		state = true;
		num = 0;
		
		GLfloat amb[] = { 0.4f, 0.4f, 0.4f, 1.0 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	}
	else{

		glEnable(GL_LIGHTING);

		glDisable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
		GLfloat position[] = { 0.5, 0.5, 1.0, 1.0 };
		glLightfv(GL_LIGHT1, GL_POSITION, position);



		glEnable(GL_LIGHT1);


	}

}

LightSource::~LightSource(){}

bool LightSource::getState(){

	return this->state;
}

void LightSource::setState(bool state){

	this->state = state;
}

GLenum LightSource::getNum(){

	return this->num;
}

void LightSource::setPosition(const Vector4 & position){

	this->position = position;
}

void LightSource::setDirection(const Vector3 & direction){

	this->direction = direction;
}

void LightSource::setCuttOff(double cut_off){

	this->cut_off = cut_off;
}

void LightSource::setExponent(double exponent){

	this->exponent = exponent;
}

void LightSource::setAmbient(const Vector4 & ambient){

	this->ambient = ambient;
}

void LightSource::setDiffuse(const Vector4 & diffuse){

	this->diffuse = diffuse;
}
void LightSource::setSpecular(const Vector4 & specular){

	this->specular = specular;
}
void LightSource::draw(){


}


void LightSource::displayLightTop () {
    
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 0.0, -25.0, 10.0, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void LightSource::displayLightCorners () {
    
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light3_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light4_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { 390.0, 390.0, 50.0, 1.0 };
    GLfloat light2_position[] = { -390.0, 390.0, 50.0, 1.0 };
    GLfloat light3_position[] = { -390.0, -390.0, 50.0, 1.0 };
    GLfloat light4_position[] = { 390.0, -390.0, 50.0, 1.0 };
    GLfloat spot_direction[] = { -1.0, -1.0, -0.5 };
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);
    
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
    
    glEnable(GL_LIGHT1);
    
    spot_direction[0] = 1.0;
    
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);
    
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);
    
    glEnable(GL_LIGHT2);
    
    spot_direction[1] = 1.0;
    
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);
    
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
    
    glEnable(GL_LIGHT3);
    
    spot_direction[0] = -1.0;
    
    glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
    glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);
    
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 2.0);
    
    glEnable(GL_LIGHT4);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void LightSource::lightTopOff () {
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void LightSource::lightCornersOff () {
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}
void LightSource::displayLightBall (int x, int y) {
    
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1, 2, 50.0, 1.0 };
    GLfloat spot_direction[] = { 0.0, 0.0, -1.0 };
    
    glLightfv(GL_LIGHT5, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT5, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT5, GL_POSITION, light_position);
    glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.0);
    glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.0);
    
    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 2.0);
    
    glEnable(GL_LIGHT5);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}
void LightSource::lightBallOff (){
    glDisable(GL_LIGHT5);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}