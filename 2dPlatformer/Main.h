#pragma once
#include "SFMLLibs.h"
#include "GlobalVariables.h"

#include "Player.h"
#include "Platform.h"

#include <iostream>
#include <vector>

int main();
template<class Ta, class Tb> bool isIntersecting(Ta& obj1, Tb& obj2) {
	return (
		obj1.right() >= obj2.left() &&
		obj2.right() >= obj1.left() &&
		obj1.bottom() >= obj2.top() &&
		obj2.bottom() >= obj1.top()
		);
}
void checkCollision(Player&, Platform&);
