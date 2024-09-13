#pragma once
#ifndef PLAYER_H
#define PLAYER_H



namespace rem1
{

	class Player
	{
	private:
		float coordX, coordY, coordZ;
		float angleX, angleY, angleZ;

	public:

		Player(float x, float y, float z);

		void motion();






		bool isPlayerOnGround();


		float getCoordX();
		float getCoordY();
		float getCoordZ();

		float getAngleX();
		float getAngleY();

		~Player();

	};






}



#endif // PLAYER_H