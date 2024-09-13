#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H



namespace rem1
{

	class Vehicle
	{
	private:
		float coordX, coordY, coordZ;
		float angleX, angleY, angleZ;

	public:

		Vehicle(float x, float y, float z);

		void motion(int forwardMove, int upMove, int rightMove);






		bool isVehicleOnGround();


		float getCoordX();
		float getCoordY();
		float getCoordZ();

		~Vehicle();

	};






}



#endif // VEHICLE_H