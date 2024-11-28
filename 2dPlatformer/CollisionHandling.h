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
		return; 
	}

	ObjectA.setIsOnGround(true);

}
