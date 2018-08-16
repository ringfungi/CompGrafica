#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "GameManager.h"


int counter;

std::vector<int> v;

GameManager *game = 0;

void keyPress(unsigned char key, int x, int y){

	game->keyPressed(key);
}

void keyUp(unsigned char key, int x, int y){

	game->keyPressedUp(key);
}

void myReshape(GLsizei w, GLsizei h){

	if (game) game->reshape(w, h);
}

void myDisplay(void){

	game->display();
}

void myTimer(int){

	game->onTimer();
}

int logSpawn(){

	if (counter >= 4)
		counter = 1;
	else
		counter++;

	return counter;
}

void incCounter(){

	counter++;
}

int randGen(){

	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(v.begin(), v.end(), g);

	return v.at(0);
}

int main(int argc, char ** argv) {

	 v.push_back(1);
	 v.push_back(2);
	 v.push_back(3);
	 v.push_back(4);

	 counter = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(-1, -1);
	glutCreateWindow("Frogger");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutIgnoreKeyRepeat(true);
	

	game = new GameManager();
	if (game) game->init();

	if (game) game->onTimer();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
    return 0;
}
