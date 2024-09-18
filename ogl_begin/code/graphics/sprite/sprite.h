#pragma once
#ifndef REM_SPRITE_H
#define REM_SPRITE_H


namespace rem
{

	class Sprite
	{
	private:

		int sizeX, sizeY;
		float originX, originY;
		float coordX, coordY;


		unsigned int texture;

		float vertexArray[8];
		unsigned int index[6];
		float texCoord[8];

	public:

		Sprite();
		~Sprite();




		void loadTexture(const char* fileName);
		void setPosition(float x, float y);
		void draw();

	};

};


#endif // REM_SPRITE_H
