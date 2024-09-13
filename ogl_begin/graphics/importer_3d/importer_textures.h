#pragma once
#ifndef IMPORTER_TEXTURES_H
#define IMPORTER_TEXTURES_H


#include <windows.h>
#include <gl/GL.h>
#include "../stb/stb_image.h"





void loadTexture(const char* fileName, unsigned int* targetTexture);

void importTextures();





extern unsigned int voidTexture, ironTexture, copperTexture;


#endif // IMPORTER_TEXTURES_H