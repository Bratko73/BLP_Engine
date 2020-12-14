#include "SFML/include/SFML/Graphics.hpp"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "TestMap.h"
#include "Enemy.h"
#include "Menu.h"
#include "Interface.h"
#include "background.h"
#include <map>

void MainMenu(sf::RenderWindow& window) {
	sf::Texture startTexture, exitTexture, titleTexture, menuBackground;
	startTexture.loadFromFile("D:/Libraries/sourses/start.png");
	exitTexture.loadFromFile("D:/Libraries/sourses/exit.png");
	titleTexture.loadFromFile("D:/Libraries/sourses/title.png");
	menuBackground.loadFromFile("D:/Libraries/sourses/MainMenuBackground.jpg");
	sf::Sprite menuStart(startTexture), menuExit(exitTexture), menuTitle(titleTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 1;
	menuTitle.setPosition(0, 0);
	menuStart.setPosition(180, 100);
	menuExit.setPosition(180, 150);

	while (isMenu)
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					if (menuNum > 1)
						menuNum = 1;
					break;
				case sf::Keyboard::Down:
					if (menuNum < 2)
						menuNum = 2;
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		menuStart.setColor(sf::Color::White);
		menuExit.setColor(sf::Color::White);

		if (menuNum == 1)
			menuStart.setColor(sf::Color::Red);
		if (menuNum == 2)
			menuExit.setColor(sf::Color::Red);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (menuNum == 1)
				isMenu = false;
			if (menuNum == 2) {
				window.close();
				return;
			}

		}
		window.draw(menuBg);
		window.draw(menuTitle);
		window.draw(menuStart);
		window.draw(menuExit);
		window.display();
	}
}

void level_1(sf::RenderWindow& window, int& lives) {

}

void level_2(sf::RenderWindow& window, int& lives) {

}

void level_3(sf::RenderWindow& window, int& lives) {

}

void level_4(sf::RenderWindow& window, int& lives) {

}

int main()
{
	//Person Player("D:/Libraries/sourses/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	sf::RenderWindow window(sf::VideoMode(400, 250), "Fuk yea!");
	/*const int lives = 4;
	GameMario Mario(lives);
	Mario.init();
	Mario.start(window);
	/**/
	background Bg("D:/Libraries/sourses/19783.ttf");
	Bg.addImageObj("D:/Libraries/sourses/castle.png");
	Bg.addTextObj(30, "Fuc' Yo' Nig'a");
	Bg.TextObjSetPosition(0, sf::Vector2f(160, 70));
	Bg.ImageObjSetPosition(0, sf::Vector2f(160, 105));
	Bg.SetBgColor(sf::Color(107, 140, 255));
	GameMap map(200, 16);
	std::map<char, Tile> TileMap ={ {' ', Tile()},
	{'b', Tile(1, "D:/Libraries/sourses/bricks.png")},
	{'P', Tile(1, "D:/Libraries/sourses/block.png")},
	{'t', Tile(1, "D:/Libraries/sourses/grassplatformTopLeft.png")},
	{'l', Tile(1, "D:/Libraries/sourses/grassplatformLeft.png")},
	{'y', Tile(1, "D:/Libraries/sourses/grassplatformTopRight.png")},
	{'r', Tile(1, "D:/Libraries/sourses/grassplatformRight.png")},
	{'0', Tile(1, "D:/Libraries/sourses/grassplatformCenter.png")},
	};
	map.loadFromFile("D:/Libraries/sourses/test.txt", TileMap);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
		//window.clear(sf::Color(107, 140, 255));
		Bg.drawBackground(window, sf::Vector2f(0,0));
		map.DrawMap(window, 0);

		//window.draw(Player.getSprite());
		window.display();
	}
	/*sf::Texture tileSet;
	tileSet.loadFromFile("D:/Libraries/sourses/Mario_tileset.png");

	Person Player("D:/Libraries/sourses/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(112, 144), 3, 14, 0.005);

	const int numberOfEnemy = 3;
	Enemy enemy[numberOfEnemy]
	{
		Enemy("D:/Libraries/sourses/Turtle.png", 0.05, sf::FloatRect(300, 208, 16, 26), 0.0005, "Turtle", 0.27),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(832, 208, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(130, 190, 16, 16), 0.0005, "Lenin", 0),
	};

	for (int i = 0; i < numberOfEnemy; i++) {
		if (enemy[i].getName() == "Lenin")
			enemy[i].setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(0, 0), 3, 2, 0.005);
		else if (enemy[i].getName() == "Turtle")
			enemy[i].setAnimationSettings(sf::Vector2i(16, 26), sf::Vector2i(388, 240), 3, 1, 0.005);
	}
	sf::Sprite tile(tileSet);
	
	Interface interface("D:/Libraries/sourses/19783.ttf");
	interface.setTitlePosition(0, sf::Vector2f(25, 20));
	interface.setTitlePosition(1, sf::Vector2f(135, 20));
	interface.setTitlePosition(2, sf::Vector2f(200, 20));
	interface.setTitlePosition(3, sf::Vector2f(300, 20));
	interface.setTitlePosition(4, sf::Vector2f(25, 2));
	interface.setTitlePosition(5, sf::Vector2f(125, 2));
	interface.setTitlePosition(6, sf::Vector2f(200, 2));
	interface.setTitlePosition(7, sf::Vector2f(300, 2));
	sf::Clock clock;
	Menu menu;
	menu.MainMenu(window);
	while (window.isOpen())
	{
		interface.updateTime(clock.getElapsedTime().asSeconds());
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
		

		Player.play(time, Player, 400, 250);
		if (Player.getLife() == true)
			for (int i = 0; i < numberOfEnemy; i++)
				enemy[i].play(time, Player, interface, enemy, i);
		

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

		for (int i = 0; i < numberOfEnemy; i++)
			window.draw(enemy[i].getSprite());
		interface.draw(window);
		window.display();
	}
   */
    return 0;
}
