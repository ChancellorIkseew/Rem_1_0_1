#pragma once
#ifndef BASE_GL_H
#define BASE_GL_H

#include <windows.h>
#include <gl/GL.h>


void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);

void DisableOpenGL(HWND, HDC, HGLRC);

void windowResize(int x, int y);

#endif // BASE_GL_H
