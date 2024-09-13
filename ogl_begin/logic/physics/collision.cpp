#ifndef COLLISION_CPP
#define COLLISION_CPP

#include "collision.h"




rem1::Collision::Collision()
{
	//type = '0';
	//coordX1 = 0; coordY1 = 0; coordZ1 = 0;
	//coordX2 = 0; coordY2 = 0; coordZ2 = 0;
	//coordX3 = 0; coordY3 = 0; coordZ3 = 0;
}

rem1::Collision::Collision(char v_type, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	type = v_type;
	coordX1 = x1; coordY1 = y1; coordZ1 = z1;
	coordX2 = x2; coordY2 = y2; coordZ2 = z2;
	coordX3 = x3; coordY3 = y3; coordZ3 = z3;
}







rem1::Collision::~Collision()
{

}









std::list<rem1::Collision*> rem1::groundCollisionsList;

std::list<rem1::Collision*> rem1::wallCollisionsList;


#endif // COLLISION_CPP