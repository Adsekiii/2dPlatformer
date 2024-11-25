#include "Player.h"

Player::Player(Vector2f position)
{
	this->player.setSize({ 64.f,64.f});
	this->player.setOrigin(this->X() + this->player.getSize().x / 2, this->Y() + this->player.getSize().y / 2);
	this->player.setPosition(position);
	this->player.setFillColor(Color::Green);
}

RectangleShape Player::drawPlayer()
{
	return this->player;
}


void Player::move(float dt)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->player.setPosition(this->X() - this->speed * dt,this->Y());
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->player.setPosition(this->X() + this->speed * dt , this->Y());
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Space) && this->isOnGround)
	{
		this->velocityY = this->jumpPower;
		this->player.setPosition(this->X(), this->Y() - this->velocityY * dt);
		this->isOnGround = false;
	}
	
	if (!isOnGround)
	{
		this->velocityY -= this->gravity * dt;
		this->player.setPosition(this->X(), this->Y() - this->velocityY * dt);
	}
	else
	{
		this->velocityY = 0;
	}


}

void Player::setIsOnGround(bool changeState) 
{
	this->isOnGround = changeState;
}


void Player::updatePlayer(float dt) 
{
	this->move(dt);
	
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