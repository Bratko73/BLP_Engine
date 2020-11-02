#include "SFML/include/SFML/Graphics.hpp"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "TestMap.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 250), "SFML works!");

	sf::Texture tileSet;
	tileSet.loadFromFile("D:/Libraries/sourses/Mario.jpg");

	Person Player("D:/Libraries/sourses/Mario.jpg");
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(100, 180), 3, 0.05);
	sf::Sprite tile(tileSet);

	sf::Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;

		if (time > 20)
			time = 20;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Player.move();
		Player.update(time, Player);


		if (Player.getRectLeft() > 200)
			Player.setOffsetX(Player.getRectLeft() - 200);

		window.clear(sf::Color(107, 140, 255));

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P')
					tile.setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));

				if (TileMap[i][j] == 'k')
					tile.setTextureRect(sf::IntRect(143, 112, 16, 16));

				if (TileMap[i][j] == 'c')
					tile.setTextureRect(sf::IntRect(143 - 16, 112, 16, 16));

				if (TileMap[i][j] == 't')
					tile.setTextureRect(sf::IntRect(0, 47, 32, 95 - 47));

				if (TileMap[i][j] == 'g')
					tile.setTextureRect(sf::IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

				if (TileMap[i][j] == 'G')
					tile.setTextureRect(sf::IntRect(145, 222, 222 - 145, 255 - 222));

				if (TileMap[i][j] == 'd')
					tile.setTextureRect(sf::IntRect(0, 106, 74, 127 - 106));

				if (TileMap[i][j] == 'w')
					tile.setTextureRect(sf::IntRect(99, 224, 140 - 99, 255 - 224));

				if (TileMap[i][j] == 'r')
					tile.setTextureRect(sf::IntRect(143 - 32, 112, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0'))
					continue;

				tile.setPosition(j * 16 - Player.getOffsetX(), i * 16 - Player.getOffsetY());
				window.draw(tile);
			}


		window.draw(Player.getSprite());
		window.display();
	}
   
    return 0;
}
