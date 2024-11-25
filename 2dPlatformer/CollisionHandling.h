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


template<class Ta, class Tb> void checkCollision(Ta& ObjectA, Tb& ObjectB)
{
	if (!isIntersecting(ObjectA, ObjectB)) 
	{ 
		return; 
	}

	ObjectA.setIsOnGround(true);

}
