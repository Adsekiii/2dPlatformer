#pragma once
#include "SFMLlibs.h"

class Platform 
{
public:

	Platform(float sizeX, float sizeY, Vector2f position);

	RectangleShape drawPlatform();

	float X();
	float Y();
	float left();
	float right();
	float top();
	float bottom();

private:
	RectangleShape platform;

};