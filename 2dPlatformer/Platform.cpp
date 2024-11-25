#include "Platform.h"

Platform::Platform(float sizeX, float sizeY, Vector2f position)
{
	this->platform.setSize({ sizeX,sizeY });
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