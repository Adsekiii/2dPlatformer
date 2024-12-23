#pragma once
#include "SFMLlibs.h"

class Player
{
public:
	Player(Vector2f position);

	void changeSpeed(float speed);
	RectangleShape drawPlayer();

	void updatePlayer(float dt);
	void move(float dt);

	void setIsOnGround(bool);
	bool getIsOnGround();

	void setIsOnWall(bool);
	bool getIsOnWall();

	void setVelocity(Vector2f);
	Vector2f getVelocity();

	float X();
	float Y();
	float left();
	float right();
	float top();
	float bottom();

private:
	
	bool isOnGround = false;
	bool isOnWall = false;
	RectangleShape player;
	float speed = 200;
	float jumpPower = 600;
	float velocityY = 0;
	float velocityX = 0;
	const float gravity = 1000;
};