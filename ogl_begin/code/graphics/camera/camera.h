#pragma once
#ifndef CAMERA_H
#define CAMERA_H


namespace rem
{
	enum mode
	{
		LINEAR = 0,
		EXPONENTIAL = 1
	};

	class Camera
	{
	private:

		float x, y;
		float basicScale;
		float currentScale;

		int scalingMode;

	public:

		Camera(float x, float y, float scale, int mode);
		Camera();
		~Camera();

		void setPosition(float x, float y);
		void setBasicScale(float scale);
		void setScaleModifier(float modifier);
		void setScalingMode(int mode);

		//POINT getPosition();
		//float getBasicScale();
		//float getScaleModifier();

		static void aply(Camera& camera);

	};

}


#endif	//	CAMERA_H
