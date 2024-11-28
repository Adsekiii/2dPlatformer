#include "Platform.h"

Platform::Platform(float sizeX, float sizeY, Vector2f position)
{
	this->platform.setSize({ sizeX,sizeY });
	this->containsPlayer.setSize(Vector2f(sizeX * 1.2, sizeY * 1.2));
	this->platform.setOrigin(this->X() + this->platform.getSize().x / 2, this->Y() + this->platform.getSize().y / 2);
	this->platform.setPosition(position);
}

RectangleShape Platform::drawPlatform()
{
	return this->platform;
}

float Platform::X()
{
	return this->platform.getPosition().x;
}
float Platform::Y()
{
	return this->platform.getPosition().y;
}


float Platform::XcontainsPlayer()
{
	return this->containsPlayer.getPosition().x;
}

float Platform::YcontainsPlayer()
{
	return this->containsPlayer.getPosition().y;
}

bool Platform::getIsPlayerNerby()
{
	return this->isPlayerNerby;
}
void Platform::setIsPlayerNerby(bool changeState)
{
	this->isPlayerNerby = changeState;
}

float Platform::left()
{
	return this->X() - this->platform.getSize().x / 2;
}
float Platform::right()
{
	return this->X() + this->platform.getSize().x / 2;
}
float Platform::top()
{
	return this->Y() - this->platform.getSize().y / 2;
}
float Platform::bottom()
{
	return this->Y() + this->platform.getSize().y / 2;
}


float Platform::containerLeft()
{
	return this->X() - this->containsPlayer.getSize().x / 2;
}
float Platform::containerRight()
{
	return this->X() + this->containsPlayer.getSize().x / 2;
}
float Platform::containerTop()
{
	return this->Y() - this->containsPlayer.getSize().y / 2;
}
float Platform::containerBottom()
{
	return this->Y() + this->containsPlayer.getSize().y / 2;
}