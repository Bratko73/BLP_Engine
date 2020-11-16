#include "SFML/include/SFML/Graphics.hpp"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "TestMap.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 250), "SFML works!");

	sf::Texture tileSet;
	tileSet.loadFromFile("D:/Libraries/sourses/Mario_tileset.png");

	Person Player("D:/Libraries/sourses/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(112, 144), 3, 14, 0.005);

	const int length = 2;
	Enemy enemy[length]
	{
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(832, 208, 16, 16), 0.0005),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(130, 190, 16, 16), 0.0005),
	};

	for (int i = 0; i < length; i++)
		enemy[i].setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(0, 0), 3, 2, 0.005);

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
		Player.isEdgeOfMap(400);

		for (int i = 0; i < length; i++) {
			enemy[i].move(enemy[i]);
			enemy[i].update(time, Player);
			enemy[i].Death(Player);
		}

		window.clear(sf::Color(107, 140, 255));

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P')
					tile.setTextureRect(sf::IntRect(95, 112, 16, 16));

				if (TileMap[i][j] == 'k')
					tile.setTextureRect(sf::IntRect(143, 112, 16, 16));

				if (TileMap[i][j] == 't')
					tile.setTextureRect(sf::IntRect(0, 47, 32, 48));

				if (TileMap[i][j] == 'g')
					tile.setTextureRect(sf::IntRect(0, 139, 48, 37));

				if (TileMap[i][j] == 'G')
					tile.setTextureRect(sf::IntRect(145, 222, 77, 33));

				if (TileMap[i][j] == 'd')
					tile.setTextureRect(sf::IntRect(0, 106, 74, 21));

				if (TileMap[i][j] == 'w')
					tile.setTextureRect(sf::IntRect(99, 224, 41, 31));

				if (TileMap[i][j] == 'r')
					tile.setTextureRect(sf::IntRect(111, 112, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0'))
					continue;

				tile.setPosition(j * 16 - Player.getOffsetX(), i * 16 - Player.getOffsetY());
				window.draw(tile);
			}


		window.draw(Player.getSprite());

		for (int i = 0; i < length; i++)
			window.draw(enemy[i].getSprite());

		window.display();
	}
   
    return 0;
}
