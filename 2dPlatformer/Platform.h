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

	float containerLeft();
	float containerRight();
	float containerTop();
	float containerBottom();

	bool getIsPlayerNerby();
	void setIsPlayerNerby(bool);

	float XcontainsPlayer();
	float YcontainsPlayer();

private:
	bool isPlayerNerby{ false };
	RectangleShape containsPlayer;
	RectangleShape platform;

};