#pragma once
#include "Player.h"
#include "Platform.h"


template<class Ta, class Tb> bool isIntersecting(Ta& ObjectA,Tb& ObjectB) {
	return  (
			ObjectA.right() >= ObjectB.left() &&
			ObjectA.left() <= ObjectB.right() &&
			ObjectA.top() <= ObjectB.bottom() &&
			ObjectA.bottom() >= ObjectB.top()
			);
}

template<class Ta, class Tb> bool isIntersectingContainer(Ta& ObjectA, Tb& ObjectB) {
	return  (
		ObjectA.right() >= ObjectB.containerLeft() &&
		ObjectA.left() <= ObjectB.containerRight() &&
		ObjectA.top() <= ObjectB.containerBottom() &&
		ObjectA.bottom() >= ObjectB.containerTop()
		);
}


template<class Ta, class Tb> void checkCollision(Ta& ObjectA, Tb& ObjectB)
{
	if (!isIntersecting(ObjectA, ObjectB)) 
	{ 
		ObjectA.setIsOnGround(false);
		ObjectA.setIsOnWall(false);
		return; 
	}

	float disT = abs(ObjectA.bottom() - ObjectB.top());
	float disB = abs(ObjectA.top() - ObjectB.bottom());
	float disL = abs(ObjectA.right() - ObjectB.left());
	float disR = abs(ObjectA.left() - ObjectB.right());

	bool hitTop = disT < disB;
	bool hitLeft = disL < disR;

	float minTopBottom = hitTop ? disT : disB;
	float minLeftRight = hitLeft ? disL : disR;

	bool hitTopBottom = minTopBottom < minLeftRight;

	if (hitTop && hitTopBottom)
	{
		ObjectA.setIsOnGround(true);
	}
	else if (!hitTop && hitTopBottom)
	{
		ObjectA.setVelocity({0,-100});
		ObjectA.setIsOnGround(false);
	}
	else if (hitLeft && !hitTopBottom)
	{
		ObjectA.setIsOnGround(false);
		ObjectA.setIsOnWall(true);
	}
	else if (!hitLeft && !hitTopBottom)
	{
		ObjectA.setIsOnGround(false);
		ObjectA.setIsOnWall(true);
	}



}
