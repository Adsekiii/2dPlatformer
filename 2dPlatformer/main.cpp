#include "Main.h"

int main()
{
	RenderWindow window({WINDOWWIDTH, WINDOWHEIGHT},"Platformer");

	vector<Platform> platforms;
	platforms.emplace_back(Platform(256.f, 64.f, { WINDOWWIDTH / 2,WINDOWHEIGHT - 100 }));
	platforms.emplace_back(Platform(256.f, 64.f, { 0,WINDOWHEIGHT - 200 }));
	platforms.emplace_back(Platform(256.f, 64.f, { WINDOWWIDTH,WINDOWHEIGHT - 200 }));
	platforms.emplace_back(Platform(256.f, 64.f, { WINDOWWIDTH / 2,WINDOWHEIGHT - 400 }));

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
		

		for (auto& platform : platforms)
		{
			if (isIntersectingContainer(player, platform))
			{
				checkCollision(player, platform);
			}
		}

		window.clear();
		///
		for (auto& platform : platforms)
		{
			window.draw(platform.drawPlatform());
		}
		window.draw(player.drawPlayer());
		///
		window.display();

	}
	return EXIT_SUCCESS;
}