#include "Main.h"

int main()
{
	RenderWindow window({WINDOWWIDTH, WINDOWHEIGHT},"Platformer");

	Platform platform1(256.f, 64.f, { WINDOWWIDTH / 2,WINDOWHEIGHT - 100 });
	Platform platform2(256.f, 64.f, { 0,WINDOWHEIGHT - 200 });
	Platform platform3(256.f, 64.f, {WINDOWWIDTH,WINDOWHEIGHT - 200});
	Player player({WINDOWWIDTH/2, WINDOWHEIGHT - 200});

	Clock inBetweenFPS;
	Time deltaTime;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		deltaTime = inBetweenFPS.restart();

		player.updatePlayer(deltaTime.asSeconds());
		if (isIntersecting(player, platform1) || isIntersecting(player, platform2) || isIntersecting(player, platform3))
		{
			player.setIsOnGround(true);
		}
		else
		{
			player.setIsOnGround(false);
		}
		

		window.clear();
		///
		window.draw(platform1.drawPlatform());
		window.draw(platform2.drawPlatform());
		window.draw(platform3.drawPlatform());
		window.draw(player.drawPlayer());
		///
		window.display();

	}
	return EXIT_SUCCESS;
}