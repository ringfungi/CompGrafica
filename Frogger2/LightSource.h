#ifndef __LIGHTSOURCE_H__
#define __LIGHTSOURCE_H__

#include "Vector3.h"
#include "Vector4.h"

class LightSource{
private:
	Vector4 ambient;
	Vector4 diffuse;
	Vector4 specular;
	Vector4 position;
	Vector3 direction;
	double cut_off;
	double exponent;
	GLenum num;
	bool state;

public:

	LightSource(GLenum number);
	~LightSource();
	bool getState();
	void setState(bool state);
	GLenum getNum();
	void setPosition(const Vector4 & position);
	void setDirection(const Vector3 & direction);
	void setCuttOff(double cut_off);
	void setExponent(double exponent);
	void setAmbient(const Vector4 & ambient);
	void setDiffuse(const Vector4 & diffuse);
	void setSpecular(const Vector4 & specular);
	void draw();
	void displayLightTop();
	void displayLightCorners();
	void lightTopOff();
	void lightCornersOff();
	void displayLightBall(int x, int y);
	void lightBallOff();
};

#endif