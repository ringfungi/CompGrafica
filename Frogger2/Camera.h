#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Entity.h"

class Camera : public Entity
{
protected:
	Vector3 up;
	Vector3 at;
	double near;
	double far;
public:
	Camera(double near, double far);
	Camera();
	~Camera();

	void update();
	void computerProjectionMatrix();
	void computerVisualizationMatrix();
};

#endif