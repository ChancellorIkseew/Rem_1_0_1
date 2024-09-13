
#include "test_game.h"
#include "../system/macros.h"

rem::Sprite testSprSulfur;
rem::Camera camera;

int scaleModifier = 2;

void testInitSprite()
{
	camera.setBasicScale(0.01f);

	testSprSulfur.loadTexture("images/sulfur.bmp");
	testSprSulfur.setPosition(-0.5, -0.5);
}

void testDrawBlock()
{
	if (MouseWheel_Up)
	{
		MouseWhell_Reset;
		scaleModifier += 2;
	}
	else if (MouseWheel_Down)
	{
		MouseWhell_Reset;
		scaleModifier -= 2;
	}

	if (scaleModifier < 1)
	{
		scaleModifier = 1;
	}
	

	camera.setPosition(0.0f, 0.0f);
	camera.setScaleModifier(scaleModifier);
	rem::Camera::aply(camera);

	testSprSulfur.draw();
}
