#include "Main.h"

int main() {

	RenderWindow window({ windowWidth,windowHeight }, "Platformer");

	vector<Platform> platforms;

	platforms.emplace_back(300.f, 50.f, Vector2f(windowWidth / 2, windowHeight - 100));
	platforms.emplace_back(300.f, 50.f, Vector2f(windowWidth, windowHeight - 200));
	platforms.emplace_back(300.f, 50.f, Vector2f(0, windowHeight-200));

	Player player(Vector2f(windowWidth /2, windowHeight - 150.f ),100.f,300.f);

	Clock clock;
	Time dt;

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
		dt = clock.restart();

		player.updatePlayer(dt.asSeconds());

		window.clear();
		for (auto& platform : platforms) {
			window.draw(platform.getShape());
			checkCollision(player, platform);
		}
		window.draw(player.getShape());
		window.display();
		
	}

	return EXIT_SUCCESS;
}

void checkCollision(Player& player, Platform& platform) {
	if (!isIntersecting(player, platform))
	{
		
		return;
	}


	float overlapLeft = abs(player.left() - platform.left());
	float overlapRight = abs(player.right() - platform.right());
	float overlapTop = abs(player.top() - platform.top());
	float overlapBottom = abs(player.bottom() - platform.bottom());

	bool hitLeft(overlapLeft < overlapRight);
	bool hitTop(overlapTop < overlapBottom);

	float minOverlapX{ hitLeft ? overlapLeft : overlapRight };
	float minOverlapY{ hitTop ? overlapTop : overlapBottom };

	if (minOverlapX < minOverlapY) {
		player.setVelocity(0.f, player.getVelocity().y);
	}
	else
	{
		player.setVelocity(player.getVelocity().x, hitTop ? 0.f : 0.f);
		if (!hitTop) {
			player.isOnGround = true;
		}
		else
		{
			player.isOnGround = false;
		}
	}

}

