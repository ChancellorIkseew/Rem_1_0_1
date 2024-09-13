#pragma once
#ifndef REM_TEXT_H
#define REM_TEXT_H

#include <string>


namespace rem
{

	class Text
	{
	private:

		int sizeX, sizeY;
		float originX, originY;
		float coordX, coordY;


		char* textValue;

		float vertexArray[8];
		unsigned int index[6];
		float texCoord[8];

	public:

		Text();
		~Text();

		void setString(char* textValue);
		void setPosition(float x, float y);
		void draw();

	};

};


#endif // REM_TEXT_H
