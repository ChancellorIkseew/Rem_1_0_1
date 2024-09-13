#ifndef IMPORTER_TEXTURES_CPP
#define IMPORTER_TEXTURES_CPP


#include "importer_textures.h"

void loadTexture(const char* fileName, unsigned int* targetTexture)
{
	int maxX, maxY, cnt;
	unsigned char* data = stbi_load(fileName, &maxX, &maxY, &cnt, 0);

	glGenTextures(1, targetTexture);
	glBindTexture(GL_TEXTURE_2D, *targetTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}

void importTextures()
{
	loadTexture("images/void_texture.bmp", &voidTexture);
	loadTexture("images/iron.bmp", &ironTexture);
	loadTexture("images/copper.bmp", &copperTexture);
}



unsigned int voidTexture, ironTexture, copperTexture;

#endif // IMPORTER_TEXTURES_CPP