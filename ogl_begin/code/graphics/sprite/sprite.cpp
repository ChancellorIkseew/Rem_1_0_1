
#include "sprite.h"

#include <windows.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"


rem::Sprite::Sprite()
{
	vertexArray[0] = 0.0f; vertexArray[1] = 0.0f;
	vertexArray[2] = 0.0f; vertexArray[3] = 1.0f;
	vertexArray[4] = 1.0f; vertexArray[5] = 0.0f;
	vertexArray[6] = 1.0f; vertexArray[7] = 1.0f;

	index[0] = 0;
	index[1] = 1;
	index[2] = 2;
	index[3] = 1;
	index[4] = 2;
	index[5] = 3;

	texCoord[0] = 0;
	texCoord[1] = 1;
	texCoord[2] = 0;
	texCoord[3] = 0;
	texCoord[4] = 1;
	texCoord[5] = 1;
	texCoord[6] = 1;
	texCoord[7] = 0;

	sizeX = 1;
	sizeY = 1;
	coordX = 0;
	coordY = 0;
	originX = 0;
	originY = 0;

	texture = 0;
}

rem::Sprite::~Sprite()
{

}



void rem::Sprite::loadTexture(const char* fileName)
{
	int maxX, maxY, cnt;
	unsigned char* data = stbi_load(fileName, &maxX, &maxY, &cnt, 0);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}


void rem::Sprite::setPosition(float x, float y)
{
	vertexArray[0] = coordX + x; vertexArray[1] = coordY + y;
	vertexArray[2] = coordX + x; vertexArray[3] = coordY + sizeY + y;
	vertexArray[4] = coordX + sizeX + x; vertexArray[5] = coordY + y;
	vertexArray[6] = coordX + sizeX + x; vertexArray[7] = coordY + sizeY + y;
}


void rem::Sprite::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glColor3f(1.0f, 1.0f, 1.0f);
	//glPushMatrix();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(2, GL_FLOAT, 0, &vertexArray);
	glTexCoordPointer(2, GL_FLOAT, 0, &texCoord);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &index);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glPopMatrix();

}


