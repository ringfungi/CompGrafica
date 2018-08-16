#include "Camera.h"

class PerspectiveCamera : public Camera
{
private:
	double fovy;
	double aspect;

public:
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
	~PerspectiveCamera();

	void uptade();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};