#include <stdlib.h>
#include <iostream>
#include "DynamicObject.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Frog.h"
#include "Car.h"
#include "TimberLog.h"
#include "Bus.h"
#include "River.h"
#include "Riverside.h"
#include "Road.h"
#include "Roadside.h"
#include "Vector3.h"
#include "LightSource.h"


void myTimer(int);
int randGen();

GameManager::GameManager(){}

GameManager::~GameManager(){}

void GameManager::display(){

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (!game_over){
        float xmin = -2., xmax = 2., ymin = -2., ymax = 2.;
        float ratio = (xmax - xmin) / (ymax - ymin);
        float aspect = (float)_w / _h;
        if (aspect > ratio){
            glViewport((_w - _h*ratio) / 2, 0, _h*ratio, _h);
        }
        else{
            glViewport(0, (_h - _w / ratio) / 2, _w, _w / ratio);
        }
        if (cameraOrtho){
            
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(xmin, xmax, ymin, ymax);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            
        }
        else if (cameraFrog){//3
            double a, b, c;
            Vector3* ola;
            ola = frogp->getPosition();
            a=ola->getX();
            b = ola->getY();
            c = ola->getZ();
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(93, _w/_h, 0.5f, 10.0f);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(a,b-1.2,c+2.4,      a,b+2.4,0,    0,0,1);
            
            
        }
        else if (cameraPerspective){//2
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(93,_w / _h, 0.5f, 10.0f);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0.0, -1.7, 2.5,     0.0, 0.0, 0.0,      0.0f, 0.0f, 1.0f);
        }
        else if (cameraPerspective1){//4
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(93,_w / _h, 0.5f, 10.0f);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(-5.0, 0.0,2.4,     0.0, 0.0, 0.0,      0.0f, 0.0f, 1.0f);
        }
    }
	
	for (std::vector<GameObject*>::iterator it2 = game_objects.begin(); it2 != game_objects.end(); ++it2) {
		(*it2)->draw();
	}

	std::vector<DynamicObject*>::iterator it;

	if (jump_log_vec){							//Draws the in-game logs when log_create points to a lower position on dynamic_log than log_destroy
					
		it = log_destroy;
		while (it != (dynamic_logs.end())){
			(*it)->draw();
			it++;
		}

		it = dynamic_logs.begin();

		while (it != (log_create + 1)){
			(*it)->draw();
			it++;
		}
	}
	else{								//Draws the in-game logs when log_destroy points to a lower position on dynamic_log than log_create (or the same position) 
		it = log_destroy;
		if ((*it)->in_game == 1){
			for (it = log_destroy; it != (log_create + 1); it++) {
				(*it)->draw();
			}
		}
	}

	if (jump_car_vec){

		it = car_destroy;
		while (it != (dynamic_cars.end())){
			(*it)->draw();
			it++;
		}

		it = dynamic_cars.begin();

		while (it != (car_create + 1)){
			(*it)->draw();
			it++;
		}
	}
	else{
		it = car_destroy;
		if ((*it)->in_game == 1){
			for (it = car_destroy; it != (car_create + 1); it++) {
				(*it)->draw();
			}
		}
	}

	if (jump_bus_vec){

		it = bus_destroy;
		while (it != (dynamic_buses.end())){
			(*it)->draw();
			it++;
		}

		it = dynamic_buses.begin();

		while (it != (bus_create + 1)){
			(*it)->draw();
			it++;
		}
	}
	else{
		it = bus_destroy;
		if ((*it)->in_game == 1){
			for (it = bus_destroy; it != (bus_create + 1); it++) {
				(*it)->draw();
			}
		}
	}


	frogp->draw();

	glFlush();
}
void GameManager::reshape(GLsizei w, GLsizei h){
    _w = w;
    _h = h;
}
void GameManager::keyPressed(unsigned char key){
   
	Vector3 speed(0, 0, 0);

	speed = frogp->getSpeed();

	if (key == 'a' || key == 'A'){
		speed += Vector3(0, -0.4, 0);
	}
	if (key == 'q' || key == 'Q'){
		speed += Vector3(0, 0.4, 0);
	}
	if (key == 'o' || key == 'O'){
		speed += Vector3(-0.4, 0, 0);
	}
	if (key == 'p' || key == 'P'){
		speed += Vector3(0.4, 0, 0);
	}
    
    else if (key == '1'){
        cameraOrtho = true;
        cameraFrog = false;
        cameraPerspective = false;
    }
    else if (key == '3'){
        cameraOrtho = false;
        cameraFrog = true;
        cameraPerspective = false;
    }
    else if (key == '2'){
        cameraOrtho = false;
        cameraFrog = false;
        cameraPerspective = true;
    }
    else if(key == '4'){
        cameraOrtho = false;
        cameraFrog = false;
        cameraPerspective = false;
        cameraPerspective1 = true;
    }
  
	else if (key == 'N' || key == 'n'){
		if (lightp->getState()){
			lightp->setState(false);
			glDisable(GL_LIGHT0);
		}
		else{
			lightp->setState(true);
			glEnable(GL_LIGHT0);
		}
	}
    
	key_speed = speed;

	frogp->setSpeed(speed);
}

void GameManager::keyPressedUp(unsigned char key){

	Vector3 speed(0, 0, 0);

	speed = frogp->getSpeed();

	if (key == 'a' || key == 'A'){
		speed -= Vector3(0, -0.4, 0);
	}
	if (key == 'q' || key == 'Q'){
		speed -= Vector3(0, 0.4, 0);
	}
	if (key == 'o' || key == 'O'){
		speed -= Vector3(-0.4, 0, 0);
	}
	if (key == 'p' || key == 'P'){
		speed -= Vector3(0.4, 0, 0);
	}

	key_speed = speed;

	frogp->setSpeed(speed);
}

void GameManager::onTimer(){
	int tact = glutGet(GLUT_ELAPSED_TIME);
	int delta_t = tact - tant;
	tant = tact;
	update(delta_t);
	glutTimerFunc(10, myTimer, 1);
	glutPostRedisplay();
}

void GameManager::createObj(char obj){


	switch (obj)
	{
		case 'c':									//Creates a car
		{
			if ((car_create == car_destroy) && ((*car_create)->in_game == 0)){
				(*car_create)->in_game = 1;
				break;
			}
			car_create++;
			if (car_create == (dynamic_cars.end())){
				car_create = dynamic_cars.begin();
				jump_car_vec = 1;
			}

			(*car_create)->in_game = 1;
			break;
		}
		case 'b':									//Creates a bus
		{
			if ((bus_create == bus_destroy) && ((*bus_create)->in_game == 0)){
				(*bus_create)->in_game = 1;
				break;
			}
			bus_create++;
			if (bus_create == (dynamic_buses.end())){
				bus_create = dynamic_buses.begin();
				jump_bus_vec = 1;
			}

			(*bus_create)->in_game = 1;
			break;
		}
		case 't':									//Creates a timber log
		{
			if ((log_create == log_destroy) && ((*log_create)->in_game == 0)){
				(*log_create)->in_game = 1;
				break;
			}
			log_create++;
			if (log_create == (dynamic_logs.end())){
				log_create = dynamic_logs.begin();
				jump_log_vec = 1;
			}
			(*log_create)->in_game = 1;
			break;
		}
		default:
			break;
	}
}

void GameManager::update(int delta_t){

	std::vector<GameObject*>::iterator it;
	std::vector<DynamicObject*>::iterator it2;


	for (it = game_objects.begin(); it != game_objects.end(); ++it) {
		(*it)->update(delta_t);
	}

	frogp->setSpeed(key_speed);

	Vector3 aux = (frogp->colisionLimits(left_limit, right_limit, up_limit, down_limit));
	frogp->setPosition(aux);

	frogp->update(delta_t, (game_speed));

	if ((frogonalog == 0) && (riverp->colision(frogp)))
		frogp->coordReset();


	it2 = log_destroy;
	/*for (std::vector<DynamicObject*>::iterator it3 = dynamic_logs.begin(); it3 != dynamic_logs.end(); ++it3) {
		std::cout << (*it3)->in_game << ' ';
	}*/

	if ((*log_destroy)->in_game == 1){
		while (it2 != (log_create + 1)){


			if ((*it2)->colisionPastLimits(left_limit, right_limit, up_limit, down_limit)){
				(*it2)->coordReset();
				log_destroy++;
				if (log_destroy == (log_create + 1)){	//Checks if destroy pointer surpasses the create pointer
					log_destroy = log_create;
				}
				if (log_destroy == (dynamic_logs.end())){	//Checks if the destroy pointer reaches past the last element
					log_destroy = dynamic_logs.begin();
					jump_log_vec = 0;
					it2 = log_destroy;
					continue;
				}
			}
			else{
				if ((*it2)->colision(frogp)){
					if (!(*it2)->frog_riding){
						key_speed += (*it2)->getSpeed();
						frogp->setSpeed(key_speed);
						(*it2)->frog_riding = 1;
						frogonalog++;
					}
				}
				else
				{
					if ((*it2)->frog_riding){
						(*it2)->frog_riding = 0;
						frogonalog--;
						key_speed -= (*it2)->getSpeed();
						frogp->setSpeed(key_speed);
					}
				}

				(*it2)->update(delta_t, game_speed);
			}
			
			if (jump_log_vec && (it2 == (dynamic_logs.end() - 1))){
				it2 = dynamic_logs.begin();
			}
			else{
				it2++;
			}
		}
	}

	it2 = car_destroy;

	if ((*car_destroy)->in_game == 1){
		while (it2 != (car_create + 1)){
			if ((*it2)->colisionPastLimits(left_limit, right_limit, up_limit, down_limit)){	
				(*it2)->coordReset();
				car_destroy++;
				if (car_destroy == (car_create + 1)){
					car_destroy = car_create;
				}
				if (car_destroy == (dynamic_cars.end())){
					car_destroy = dynamic_cars.begin();
					jump_car_vec = 0;
					it2 = car_destroy;
					continue;
				}
			}
			else{
				if ((*it2)->colision(frogp)){
					frogp->coordReset();
					return;
				}
				(*it2)->update(delta_t, game_speed);
			}

			if (jump_car_vec && (it2 == (dynamic_cars.end() - 1)))
				it2 = dynamic_cars.begin();
			else
				it2++;
		}
	}

	it2 = bus_destroy;

	if ((*bus_destroy)->in_game == 1){
		while (it2 != (bus_create + 1)){
			if ((*it2)->colisionPastLimits(left_limit, right_limit, up_limit, down_limit)){
				(*it2)->coordReset();
				bus_destroy++;
				if (bus_destroy == (bus_create + 1)){
					bus_destroy = bus_create;
				}
				if (bus_destroy == (dynamic_buses.end())){
					bus_destroy = dynamic_buses.begin();
					jump_bus_vec = 0;
					it2 = bus_destroy;
					continue;
				}
			}
			else{
				if ((*it2)->colision(frogp)){
					frogp->coordReset();
					return;
				}
				(*it2)->update(delta_t, game_speed);
			}

			if (jump_bus_vec && (it2 == (dynamic_buses.end() - 1)))
				it2 = dynamic_buses.begin();
			else
				it2++;
		}
	}

	road_timer += delta_t;
	river_timer += delta_t;
	speed_timer += delta_t;

	if (river_timer >= RIVER_CADENCE){
		createObj('t');
		river_timer -= RIVER_CADENCE;
	}

	if (road_timer >= ROAD_CADENCE){
		if (randGen() <= 2)
			createObj('c');
		else
			createObj('b');

		road_timer -= ROAD_CADENCE;
	}

	if (speed_timer >= SPEED_CADENCE){
		game_speed += 0.0001;
		speed_timer -= SPEED_CADENCE;
	}
	
}

void GameManager::vectorFiller(){

	std::vector<DynamicObject*>::iterator it;

	for (int i = 0; i < total_logs; i++){

		TimberLog *timberlog = new TimberLog();
		dynamic_logs.push_back(timberlog);
	}

	for (int i = 0; i < total_cars; i++){

		Car *car = new Car();
		dynamic_cars.push_back(car);
	}

	for (int i = 0; i < total_buses; i++){

		Bus *bus = new Bus();
		dynamic_buses.push_back(bus);
	}

	log_create = dynamic_logs.begin();
	log_destroy = dynamic_logs.begin();
	car_create = dynamic_cars.begin();
	car_destroy = dynamic_cars.begin();
	bus_create = dynamic_buses.begin();
	bus_destroy = dynamic_buses.begin();
}

void GameManager::init(){

	Frog *frog = new Frog();
	Road *road = new Road();
	Roadside *roadside = new Roadside();
	River *river = new River();
	Riverside *riverside = new Riverside();
	LightSource *lightsource = new LightSource(0);
	LightSource *lightsource1 = new LightSource(1);


	left_limit = -1.97;
	right_limit = 1.97f;
	up_limit = 1.97f;
	down_limit = -1.97f;

	river_timer = 0;
	road_timer = 0;
	speed_timer = 0;
	game_speed = 0.002;
	frogonalog = 0;
	jump_bus_vec = 0;
	jump_car_vec = 0;
	jump_log_vec = 0;
	total_cars = 30;
	total_buses = 70;
	total_logs = 30;


	vectorFiller();
	
	frogp = (DynamicObject*)frog;
	riverp = river;
	lightp = lightsource;

	key_speed.set(0,0,0);

	tant = glutGet(GLUT_ELAPSED_TIME);

	game_objects.push_back(river);
	game_objects.push_back(road);
	game_objects.push_back(roadside);
	game_objects.push_back(riverside);
    
    cameraOrtho = true;
}