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

void InterfaceInit(Interface& interface) {
	interface.setTitlePosition(0, sf::Vector2f(25, 20));
	interface.setTitlePosition(1, sf::Vector2f(135, 20));
	interface.setTitlePosition(2, sf::Vector2f(200, 20));
	interface.setTitlePosition(3, sf::Vector2f(300, 20));
	interface.setTitlePosition(4, sf::Vector2f(25, 2));
	interface.setTitlePosition(5, sf::Vector2f(125, 2));
	interface.setTitlePosition(6, sf::Vector2f(200, 2));
	interface.setTitlePosition(7, sf::Vector2f(300, 2));
}
void level_init(int level, background& Bg, GameMap& map, std::map<char, Tile>& TileMap) {
	map.ClearMap();
	Bg.clearBg();
	switch (level)
	{
	case 1:
		map.loadFromFile("D:/Libraries/sourses/level_1.txt", TileMap);
		Bg.addTexture("cloudS","D:/Libraries/sourses/cloudS.png");
		Bg.addTexture("cloudXXL","D:/Libraries/sourses/cloudXXL.png");
		Bg.addTexture("holm","D:/Libraries/sourses/holm.png");
		Bg.addTexture("castle","D:/Libraries/sourses/castle.png");
		Bg.addImageObj("cloudS");
		Bg.addImageObj("cloudS");
		Bg.addImageObj("cloudS");
		Bg.addImageObj("cloudXXL");
		Bg.addImageObj("castle");
		Bg.ImageObjSetPosition(0, sf::Vector2f(1232, 152));
		Bg.ImageObjSetPosition(1, sf::Vector2f(1360, 152));
		Bg.ImageObjSetPosition(2, sf::Vector2f(2304, 104));
		Bg.ImageObjSetPosition(3, sf::Vector2f(1808, 100));
		Bg.ImageObjSetPosition(4, sf::Vector2f(2832, 104));
		Bg.addTextObj(20, "Instead of moving forward, we must move back.");
		Bg.TextObjSetPosition(0, sf::Vector2f(2832, 50));
		Bg.SetBgColor(sf::Color(100, 100, 255));		

		break;
	case 2:
		break;
	case 3:
		break;
	default:

		break;
	}

	
}

void level_1(sf::RenderWindow& window, int& lives, GameMap& map, Interface& interface, Person& Player, std::map<char, Tile>& TileMap) {
	int level = 1;
	background Bg("D:/Libraries/sourses/19783.ttf");

	level_init(level, Bg, map, TileMap);
	Enemy enemy[7]
	{
		//Enemy("D:/Libraries/sourses/Turtle.png", 0.05, sf::FloatRect(300, 208, 16, 26), 0.0005, "Turtle", 0.27),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(400, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(512, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(1760, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(1872, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(2000, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(2512, 176, 16, 16), 0.0005, "Lenin", 0),
		Enemy("D:/Libraries/sourses/Mario_tileset.png", 0.05, sf::FloatRect(2816, 176, 16, 16), 0.0005, "Lenin", 0),
	};
	for (int i = 0; i < 7; i++) {
		if (enemy[i].getName() == "Lenin")
			enemy[i].setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(0, 0), 3, 2, 0.005);
		else if (enemy[i].getName() == "Turtle")
			enemy[i].setAnimationSettings(sf::Vector2i(16, 26), sf::Vector2i(388, 240), 3, 1, 0.005);
	}

	sf::Font font;
	font.loadFromFile("D:/Libraries/sourses/19783.ttf");
	sf::Text test(" ", font,20);
	test.setPosition(300, 100);
	sf::Clock clock;
	bool Islevel = true;
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
		if (Player.getLife() == true) {
			Player.move();
			Player.update(time, map);
			Player.isEdgeOfMap(400);
			for (int i = 0; i < 7; i++) {
				enemy[i].move(map);
				enemy[i].update(time, Player);
				enemy[i].Death(Player, interface);
			}
		}
		else {
			Player.Death(250);
			lives--;
		}
		test.setString(std::to_string(Player.getRectangle().top) + "," + std::to_string(Player.getRectangle().left));
		Bg.drawBackground(window, Player.getOffsetX());
		map.DrawMap(window, Player.getOffsetX());
		for (int i = 0; i < 7; i++)
			window.draw(enemy[i].getSprite());
		window.draw(Player.getSprite());
		interface.draw(window);
		window.draw(test);
		window.display();
	}
	window.close();
}

void level_2(sf::RenderWindow& window, int& lives) {

}

void level_3(sf::RenderWindow& window, int& lives) {

}


int main()
{
	sf::Vector2i windowSize(400, 250);
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "Fuk yea!");
	int lives = 4;
	background Bg("D:/Libraries/sourses/19783.ttf");
	GameMap map(200, 17);	
	Interface interface("D:/Libraries/sourses/19783.ttf");
	Person Player("D:/Libraries/sourses/spacemanWalk.png", 0.1,0.0005,0.23,sf::FloatRect(100,180,16,16));
	Player.setAnimationSettings(sf::Vector2i(16, 13), sf::Vector2i(0, 0), 14, 0, 0.01);
	InterfaceInit(interface);

	Tile Bricks(1, "D:/Libraries/sourses/bricks.png");
	Tile Block(1, "D:/Libraries/sourses/block.png");
	Tile OStone(1, "D:/Libraries/sourses/orangestone.png");
	Tile svOStone(0, "D:/Libraries/sourses/orangestone.png");
	Tile GPTL(1, "D:/Libraries/sourses/grassplatformTopLeft.png");
	Tile GPL(1, "D:/Libraries/sourses/grassplatformLeft.png");
	Tile GPTR(1, "D:/Libraries/sourses/grassplatformTopRight.png");
	Tile GPR(1, "D:/Libraries/sourses/grassplatformRight.png");
	Tile GPTC(1, "D:/Libraries/sourses/grassplatformTopCenter.png");
	Tile GPC(1, "D:/Libraries/sourses/grassplatformCenter.png");
	Tile FreeSpace(0, "D:/Libraries/sourses/freespace.png", 1);
	Tile DeathBlock(0, "D:/Libraries/sourses/blockcc.png", 1);
	std::map<char, Tile> TileMap ={ {' ', Tile()},
	{'d', DeathBlock},
	{'b', Bricks},
	{'P', Block},
	{'s', OStone},
	{'S', svOStone},
	{'L', GPTL},
	{'l', GPL},
	{'R', GPTR},
	{'r', GPR},
	{'C', GPTC},
	{'c', GPC},
	{'0', FreeSpace},
	};


	level_1(window, lives, map, interface, Player,TileMap);
	/*map.loadFromFile("D:/Libraries/sourses/test.txt", TileMap);
	interface.increaceScore(15);
	sf::Clock clock;
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
		if (Player.getLife() == true) {
			Player.move();
			Player.update(time, map);
			Player.isEdgeOfMap(400);
			/*for (int i = 0; i < numberOfEnemy; i++) {
				enemy[i].move(map);
				enemy[i].update(time, Player);
				enemy[i].Death(Player, interface);
			}
		}
		else
			Player.Death(250);
		//window.clear(sf::Color(107, 140, 255));
		Bg.drawBackground(window, Player.getOffsetX());
		map.DrawMap(window, Player.getOffsetX());
		window.draw(Player.getSprite());
		interface.draw(window);
		window.display();
	}*/
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
		

		if (Player.getLife() == true) {
            Player.move();
            Player.update(time, map);
            Player.isEdgeOfMap(400);
            for (int i = 0; i < numberOfEnemy; i++) {
                enemy[i].move(map);
                enemy[i].update(time, Player);
                enemy[i].Death(Player, interface);
            }
        }
        else
            Player.Death(250);
		

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
