#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include <vector>
#include "GameObject.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Camera.h"
#include "LightSource.h"

class GameManager
{
private:
    bool cameraOrtho,cameraFrog,cameraPerspective,game_over, light, cameraPerspective1;
    double xmin,xmax,ymin,ymax,xcale,yscale;
    GLsizei _w;
    GLsizei _h;
    
    
		std::vector<GameObject*> game_objects;
		std::vector<DynamicObject*> dynamic_cars;
		std::vector<DynamicObject*> dynamic_buses;
		std::vector<DynamicObject*> dynamic_logs;

		std::vector<DynamicObject*>::iterator car_destroy, car_create, bus_destroy, bus_create, log_destroy, log_create;
	
		Vector3 key_speed;
		LightSource* sources;
		Camera* cameras;
		int tant, river_timer, road_timer, speed_timer, frogonalog, jump_car_vec, jump_bus_vec, jump_log_vec, total_cars, total_buses, total_logs;
		double left_limit, right_limit, up_limit, down_limit;
		double game_speed;
		static const int RIVER_CADENCE=1500, ROAD_CADENCE=1500, SPEED_CADENCE = 5000;
public:
	DynamicObject* frogp;
	StaticObject* riverp;
	LightSource* lightp;

	GameManager();
	~GameManager();

	void display();
	void reshape(GLsizei w, GLsizei h);
	void keyPressed(unsigned char key);
	void keyPressedUp(unsigned char key);
	void onTimer();
	void update(int delta_t);
	void vectorFiller();
	void init();
	void createObj(char obj);
};

#endif