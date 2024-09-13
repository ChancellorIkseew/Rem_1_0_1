#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include <list>

namespace rem1
{
	// Collision types
	// 't' - triangle
	// 'q' - quad, rectangle

	struct Collision
	{
	public:
		char type = '0';
		float coordX1 = 0, coordY1 = 0, coordZ1 = 0;
		float coordX2 = 0, coordY2 = 0, coordZ2 = 0;
		float coordX3 = 0, coordY3 = 0, coordZ3 = 0;

		Collision();

		Collision(char type, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);

		~Collision();
	};



	bool cheekcOneCollision();







	extern std::list<Collision*> groundCollisionsList;

	extern std::list<Collision*> wallCollisionsList;
}



#endif // COLLISION_H