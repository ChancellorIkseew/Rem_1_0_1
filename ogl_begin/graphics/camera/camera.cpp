
#include "camera.h"

#include <windows.h>
#include <gl/gl.h>
#include <math.h>


rem::Camera::Camera(float x, float y, float scale, int mode)
{
	this->x = x;
	this->y = y;

	basicScale = 1.0f;
	currentScale = scale;
	scalingMode = mode;
}

rem::Camera::Camera()
{
	x = 0;
	y = 0;

	basicScale = 1.0f;
	currentScale = 1.0f;
	scalingMode = EXPONENTIAL;
}

rem::Camera::~Camera()
{

}


void rem::Camera::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void::rem::Camera::setBasicScale(float scale)
{
	basicScale = scale;
}

void::rem::Camera::setScaleModifier(float modifier)
{
	if (scalingMode == LINEAR)
		currentScale = basicScale * modifier;
	else
		currentScale = basicScale * modifier * modifier;
}

void::rem::Camera::setScalingMode(int mode)
{
	scalingMode = mode;
}

void rem::Camera::aply(Camera& camera)
{
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 0);
	glTranslatef(camera.x, camera.y, 2);
	glScalef(camera.currentScale, camera.currentScale, 1);
}


