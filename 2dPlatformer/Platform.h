#pragma once
#include "SFMLLibs.h"
#include "GlobalVariables.h"

#include "Player.h"

class Platform {
public:
	Platform(float sizeX, float sizeY, Vector2f position);
	RectangleShape getShape();
	float left();
	float right();
	float top();
	float bottom();
	float X();
	float Y();

private:
	RectangleShape platform;
};