#pragma once
#ifndef PLAYER_CPP
#define PLAYER_CPP


#include "player.h"

#include "collision.h"

#include <windows.h>
#include <math.h>


rem1::Player::Player(float x, float y, float z)
{
	coordX = x; coordY = y; coordZ = z;
	angleX = 0; angleY = 0; angleZ = 0;
}

void rem1::Player::motion()
{
	float speed = 0.1f;

	//int forwardMove, rightMove, upMove;

	int forwardMove = (GetKeyState('S') < 0 ? 1 : (GetKeyState('W') < 0 ? -1 : 0));
	//freeCam.y = (GetKeyState(VK_SPACE) < 0 ? 1 : (GetKeyState(VK_SHIFT) < 0 ? -1 : 0));
	int rightMove = (GetKeyState('D') < 0 ? 1 : (GetKeyState('A') < 0 ? -1 : 0));

	POINT cur;
	POINT base = { 360, 360 };	// Window_pixel_center
	GetCursorPos(&cur);
	float xDegree = (base.y - cur.y) * speed;
	float yDegree = (base.x - cur.x) * speed;
	SetCursorPos(base.x, base.y);

	angleX = angleX + xDegree;
	if (angleX < 0) angleX = angleX + 360;
	else if (angleX > 360) angleX = angleX - 360;

	angleY = angleY + yDegree;
	if (angleY < 0) angleY = angleY + 360;
	else if (angleY > 360) angleY = angleY - 360;

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

	if (isPlayerOnGround())
	{
		if (speed != 0)	// WASD_motion
		{
			coordX = coordX + sin(angle) * speed;
			coordZ = coordZ + cos(angle) * speed;
		}

		if (GetKeyState(VK_SPACE) < 0) // jump
			coordY = coordY + 1;
	}
	else
	{
		coordY = coordY - 0.01;	// free_fall
	}

}






bool  rem1::Player::isPlayerOnGround()
{
	for (std::list<rem1::Collision*>::iterator it = rem1::groundCollisionsList.begin(); it != rem1::groundCollisionsList.end(); ++it)
	{


		if (coordY <= (*it)->coordY1)
		{
			return true;
		}

	}

	return false;
}








float  rem1::Player::getCoordX() { return coordX; }
float  rem1::Player::getCoordY() { return coordY; }
float  rem1::Player::getCoordZ() { return coordZ; }

float  rem1::Player::getAngleX() { return angleX; }
float  rem1::Player::getAngleY() { return angleY; }

rem1::Player::~Player()
{

}












#endif // PLAYER_CPP