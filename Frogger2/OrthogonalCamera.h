#include "Camera.h"

class OrthogonalCamera : public Camera
{
private:
	double left;
	double right;
	double bottom;
	double top;

public:
	OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
	~OrthogonalCamera();

	void computeProjectionMatrix();
	void computeVisulizationMatrix();
	void update();
};