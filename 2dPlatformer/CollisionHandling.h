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

