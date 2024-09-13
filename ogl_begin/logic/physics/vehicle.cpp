#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include "vehicle.h"
#include "collision.h"

#include <math.h>
#include <list>




rem1::Vehicle::Vehicle(float x, float y, float z)
{
	coordX = x; coordY = y; coordZ = z;
	angleX = 0; angleY = 0; angleZ = 0;
}


void rem1::Vehicle::motion(int forwardMove, int upMove, int rightMove)
{
	float speed = 0.1f;

	float angle = angleY * 0.01745f; // pi/180 = 0.01745;

	if (forwardMove > 0)
		angle += rightMove > 0 ? 0.785f : (rightMove < 0 ? -0.785f : 0);
	if (forwardMove < 0)
		angle += 3.14f + (rightMove > 0 ? -0.785f : (rightMove < 0 ? 0.785f : 0));
	if (forwardMove == 0)
	{
		angle += rightMove > 0 ? 1.57f : -1.57f;
		if (rightMove == 0) speed = 0;
	}

	if (speed != 0)
	{
		coordX = coordX + sin(angle) * speed;
		coordZ = coordZ + cos(angle) * speed;
	}

	if (isVehicleOnGround())
	{
		coordY = coordY - 0.01;	// free_fall
	}

}

bool rem1::Vehicle::isVehicleOnGround()
{
	for (std::list<rem1::Collision*>::iterator it = rem1::groundCollisionsList.begin(); it != rem1::groundCollisionsList.end(); ++it)
	{
		

		if (coordY > (*it)->coordY1)
		{
			return true;
		}

	}

	return false;
}



float rem1::Vehicle::getCoordX() { return coordX; }
float rem1::Vehicle::getCoordY() { return coordY; }
float rem1::Vehicle::getCoordZ() { return coordZ; }

rem1::Vehicle::~Vehicle()
{

}







#endif // VEHICLE_H
