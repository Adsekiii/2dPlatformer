#pragma once
#include "SFMLLibs.h"
#include "GlobalVariables.h"

#include "Platform.h"

class Player
{
public:
	bool isOnGround;

	Player(Vector2f position, float speed, float jumpPower);
	RectangleShape getShape();
	float left();
	float right();
	float top();
	float bottom();
	float X();
	float Y();

	void setVelocity(float veloX, float veloY);
	Vector2f getVelocity();


	void updatePlayer(float dt);
	void movePlayer(float dt);

private:
	RectangleShape player;
	float playerSpeed;
	float jumpPower;
	Vector2f playerVelocity;
};