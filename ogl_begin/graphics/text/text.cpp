
#include "text.h"

#include <windows.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

#include "../stb/stb_easy_font.h"

rem::Text::Text()
{
	std::string str1 = "000";
	//textValue = (&str1);
}

rem::Text::~Text()
{

}



void rem::Text::setString(char* textValue)
{

}

void rem::Text::setPosition(float x, float y)
{

}

void rem::Text::draw()
{
	static char buffer[99999]; // ~500 chars
	int num_quads;

	num_quads = stb_easy_font_print(0, 0, textValue, NULL, buffer, sizeof(buffer));

	glColor3f(255, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 16, buffer);
	glDrawArrays(GL_QUADS, 0, num_quads * 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}
