#include "Player.h"

Player::Player(Vector2f position, float speed, float jumpPower)
{
	this->player.setFillColor(Color::Red);
	this->player.setSize(Vector2f(50.f,50.f));
	this->player.setOrigin(this->X() + 25.f, this->Y() + 25.f);
	this->player.setPosition(position);
	this->isOnGround = true;
	this->playerSpeed = speed;
	this->jumpPower = jumpPower;
}

void Player::movePlayer(float dt)
{
	if (Keyboard::isKeyPressed(Keyboard::A)) 
	{
		this->playerVelocity.x = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->playerVelocity.x = 1;
	}
	else
	{
		this->playerVelocity.x = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space) && this->isOnGround)
	{
		this->isOnGround = false;
		this->playerVelocity.y = -1;
	}
	else if (!this->isOnGround)
	{
			this->playerVelocity.y += 1.f * dt;
	}
}

void Player::setVelocity(float veloX, float veloY) {
	this->playerVelocity = Vector2f(veloX,  veloY);
}

Vector2f Player::getVelocity() {
	return this->playerVelocity;
}


void Player::updatePlayer(float dt) {
	movePlayer(dt);
	this->player.setPosition(this->X() + (this->playerVelocity.x * this->playerSpeed * dt),
							 this->Y() + (this->playerVelocity.y * this->jumpPower * dt));
}


RectangleShape Player::getShape()
{
	return this->player;
}

float Player::X()
{
	return this->player.getPosition().x;
}
float Player::Y()
{
	return this->player.getPosition().y;
}

float Player::left()
{
	return this->X() - this->player.getSize().x / 2;
}
float Player::right()
{
	return this->X() + this->player.getSize().x / 2;
}
float Player::top()
{
	return this->Y() - this->player.getSize().y / 2;
}
float Player::bottom()
{
	return this->Y() + this->player.getSize().y / 2;
}