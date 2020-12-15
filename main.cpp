#include "SFML/include/SFML/Graphics.hpp"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "TestMap.h"
#include "Enemy.h"
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
				return;
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

void BlackScreen(sf::RenderWindow& window,int& lives, float time) {
	background Bg("D:/Libraries/sourses/19783.ttf");
	Bg.addTextObj(15, "X");
	Bg.addTextObj(30, std::to_string(lives));
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Zefir", "D:/Libraries/sourses/zefir.png");
	Bg.addImageObj("Zefir");
	Bg.TextObjSetPosition(0, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 - 5));
	Bg.TextObjSetPosition(1, sf::Vector2f(window.getSize().x / 2+16, window.getSize().y / 2 - 16));
	Bg.ImageObjSetPosition(0, sf::Vector2f(window.getSize().x / 2-26, window.getSize().y / 2));
	sf::Clock clock;

	while (window.isOpen())
	{
		time -= clock.getElapsedTime().asSeconds();
		if (time < 0)
			return;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Bg.drawBackground(window,0);
		window.display();
	}
}
void LoseScreen(sf::RenderWindow& window, float time) {
	background Bg("D:/Libraries/sourses/19783.ttf");
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Tramp", "D:/Libraries/sourses/tramp.jpg");
	Bg.addImageObj("Tramp");
	Bg.ImageObjSetPosition(0, sf::Vector2f(0, 0));
	sf::Clock clock;

	while (window.isOpen())
	{
		time -= clock.getElapsedTime().asSeconds();
		if (time < 0)
			return;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Bg.drawBackground(window, 0);
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
	Bg.clearOffSet();
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
		Bg.addImageObj("cloudS");
		Bg.addImageObj("cloudXXL");
		Bg.addImageObj("cloudXXL");
		Bg.addImageObj("holm");
		Bg.addImageObj("holm");
		Bg.addImageObj("cloudS");
		Bg.ImageObjSetPosition(0, sf::Vector2f(1232, 152));//cloudS
		Bg.ImageObjSetPosition(1, sf::Vector2f(1360, 152));//cloudS
		Bg.ImageObjSetPosition(2, sf::Vector2f(2304, 104));//cloudS
		Bg.ImageObjSetPosition(3, sf::Vector2f(1808, 100));//cloudXXL
		Bg.ImageObjSetPosition(4, sf::Vector2f(2835, 104));//castle
		Bg.ImageObjSetPosition(5, sf::Vector2f(32, 88));//cloudS
		Bg.ImageObjSetPosition(6, sf::Vector2f(512, 60));//cloudXXL
		Bg.ImageObjSetPosition(7, sf::Vector2f(1000, 50));//cloudXXL
		Bg.ImageObjSetPosition(8, sf::Vector2f(250, 190));//holm
		Bg.ImageObjSetPosition(9, sf::Vector2f(50, 175));//holm
		Bg.ImageObjSetPosition(10, sf::Vector2f(866,106));//cloudS
		Bg.addTextObj(20, "Instead of moving forward, we must move back.");
		Bg.TextObjSetPosition(0, sf::Vector2f(2800, 50));
		Bg.SetBgColor(sf::Color(100, 100, 255));		



		break;
	case 2:
		break;
	}

	
}

void level_1(sf::RenderWindow& window, int& lives, GameMap& map, background& Bg, Interface& interface, std::map<char, Tile>& TileMap, bool& isLevelPassed) {
	int level = 1;
	//background Bg("D:/Libraries/sourses/19783.ttf");
	Person Player("D:/Libraries/sourses/spacemanWalk.png", 0.1, 0.0005, 0.23, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 13), sf::Vector2i(0, 0), 14, 0, 0.01);
	Player.setRectangleLeft(100);
	Player.setRectangleTop(180);
	Player.clearOffSet();
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
	sf::Clock clock;
	bool Islevel = true;
	bool isTriggered = false;
	bool isFirsttime = true;
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
		if (Player.getRectangleLeft() > 2650)
			isTriggered = 1;
		if (isTriggered && Player.getRectangleLeft() < 90) {
			isLevelPassed = true;
			return;
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
			Player.setLife(true);
			isLevelPassed = false;
			return;
		}
		
		Bg.drawBackground(window, Player.getOffsetX());
		map.DrawMap(window, Player.getOffsetX());
		for (int i = 0; i < 7; i++)
			window.draw(enemy[i].getSprite());
		window.draw(Player.getSprite());
		interface.draw(window);
		window.display();
	}
}

void level_2(sf::RenderWindow& window, int& lives) {

}



int main()
{
	sf::Vector2i windowSize(400,250);
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "Fuk yea!");
	int lives = 3;
	background Bg("D:/Libraries/sourses/19783.ttf");
	GameMap map(200, 17);	
	Interface interface("D:/Libraries/sourses/19783.ttf");

	InterfaceInit(interface);

	Tile Bricks(1, "D:/Libraries/sourses/bricks.png",0,1);
	Tile Block(1, "D:/Libraries/sourses/block.png");
	Tile OStone(1, "D:/Libraries/sourses/orangestone.png");
	Tile invOStone(0, "D:/Libraries/sourses/orangestone.png");
	Tile GPTL(1, "D:/Libraries/sourses/grassplatformTopLeft.png");
	Tile GPL(1, "D:/Libraries/sourses/grassplatformLeft.png");
	Tile GPTR(1, "D:/Libraries/sourses/grassplatformTopRight.png");
	Tile GPR(1, "D:/Libraries/sourses/grassplatformRight.png");
	Tile GPTC(1, "D:/Libraries/sourses/grassplatformTopCenter.png");
	Tile GPC(1, "D:/Libraries/sourses/grassplatformCenter.png");
	Tile FreeSpace(1, "D:/Libraries/sourses/freespace.png");
	Tile DeathBlock(1, "D:/Libraries/sourses/freespace.png", 1);
	std::map<char, Tile> TileMap ={ {' ', Tile()},
	{'d', DeathBlock},
	{'b', Bricks},
	{'P', Block},
	{'s', OStone},
	{'S', invOStone},
	{'L', GPTL},
	{'l', GPL},
	{'R', GPTR},
	{'r', GPR},
	{'C', GPTC},
	{'c', GPC},
	{'0', FreeSpace},
	};
	bool isLevelPassed_1 = false;
	MainMenu(window);
	while (window.isOpen())
	{
		if (lives) {
			BlackScreen(window, lives, 1000);
			level_1(window, lives, map, Bg, interface, TileMap, isLevelPassed_1);
			if (isLevelPassed_1)
				level_2(window, lives);
		}
		else
		{
			LoseScreen(window, 1000);
			MainMenu(window);
			lives = 3;
			isLevelPassed_1 = false;
		}

	}
    return 0;
}
