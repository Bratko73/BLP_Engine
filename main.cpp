#include "SFML/include/SFML/Graphics.hpp"
#include "SFML/include/SFML/Audio.hpp"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "Gumba.h"
#include "Turtle.h"
#include "Interface.h"
#include "background.h"
#include <map>
#include "BonusMushroom.h"

void MainMenu(sf::RenderWindow& window) {
	sf::Texture startTexture, exitTexture, titleTexture, menuBackground;
	startTexture.loadFromFile("sourses/sprites/start.png");
	exitTexture.loadFromFile("sourses/sprites/exit.png");
	titleTexture.loadFromFile("sourses/sprites/title.png");
	menuBackground.loadFromFile("sourses/sprites/MainMenuBackground.jpg");
	sf::Sprite menuStart(startTexture), menuExit(exitTexture), menuTitle(titleTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 1;
	menuTitle.setPosition(0, 0);
	menuStart.setPosition(180, 100);
	menuExit.setPosition(180, 150);
	sf::Music music;
	music.openFromFile("sourses/sounds/narwhal.ogg");
	music.setLoop(true);
	music.setVolume(50);
	music.play();
	while (window.isOpen())
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
				return;
			if (menuNum == 2) {
				window.close();
				return;
			}
			music.pause();
		}
		window.draw(menuBg);
		window.draw(menuTitle);
		window.draw(menuStart);
		window.draw(menuExit);
		window.display();
	}
}

void BlackScreen(sf::RenderWindow& window,int& lives, float time) {
	background Bg("sourses/fonts/19783.ttf");
	Bg.addTextObj(15, "X", sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 - 5));
	Bg.addTextObj(30, std::to_string(lives), sf::Vector2f(window.getSize().x / 2 + 16, window.getSize().y / 2 - 16));
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Zefir", "sourses/sprites/zefir.png");
	Bg.addImageObj("Zefir", sf::Vector2f(window.getSize().x / 2 - 26, window.getSize().y / 2));
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
		window.clear();
		Bg.drawBackground(window,0);
		window.display();
	}
}
void LoseScreen(sf::RenderWindow& window, float time) {
	background Bg("sourses/fonts/19783.ttf");
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Tramp", "sourses/sprites/tramp.jpg");
	Bg.addImageObj("Tramp", sf::Vector2f(0, 0));


	while (window.isOpen())
	{
		time -= 0.05;
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

void WinScreen(sf::RenderWindow& window) {
	background Bg("sourses/fonts/19783.ttf");
	Bg.SetBgColor(sf::Color::Cyan);
	Bg.addTexture("Tramp", "sourses/sprites/Grazies.png");
	Bg.addImageObj("Tramp", sf::Vector2f(0, 0));
	sf::Music music;
	music.openFromFile("sourses/sounds/WhalShark.ogg");
	music.setLoop(true);
	music.setVolume(30);
	music.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Enter)
				return;
		}
		Bg.drawBackground(window, 0);
		window.display();
	}
}

void InterfaceInit(Interface& interface) {
	interface.setTitlePosition(0, sf::Vector2f(25, 20));
	interface.setTitlePosition(1, sf::Vector2f(200, 20));
	interface.setTitlePosition(2, sf::Vector2f(300, 20));
	interface.setTitlePosition(3, sf::Vector2f(25, 2));
	interface.setTitlePosition(4, sf::Vector2f(200, 2));
	interface.setTitlePosition(5, sf::Vector2f(300, 2));
	interface.setTitlePosition(6, sf::Vector2f(135, 20));
	interface.setTitlePosition(7, sf::Vector2f(125, 2));
}
void level_init(int level, background& Bg, GameMap& map, std::map<char, Tile>& TileMap) {
	map.ClearMap();
	Bg.clearBg();
	Bg.clearOffSet();
	int countOfRepeats = 5;
	switch (level)
	{
	case 1:
		map.loadFromFile("sourses/levels/level_1.txt", TileMap);
		Bg.addTexture("cloudS","sourses/sprites/cloudS.png");
		Bg.addTexture("cloudXL", "sourses/sprites/cloudXL.png");
		Bg.addTexture("cloudXXL","sourses/sprites/cloudXXL.png");
		Bg.addTexture("shrubS", "sourses/sprites/shrubS.png");
		Bg.addTexture("shrubXL", "sourses/sprites/shrubXL.png");
		Bg.addTexture("shrubXXL", "sourses/sprites/shrubXXL.png");
		Bg.addTexture("holm","sourses/sprites/holm.png");
		Bg.addTexture("castle","sourses/sprites/castle.png");

		for (int i = 0; i < countOfRepeats; i++) {
			Bg.addImageObj("cloudS", sf::Vector2f(160 + 800 * i, 60));
			Bg.addImageObj("cloudS", sf::Vector2f(300 + 800 * i, 32));
			Bg.addImageObj("cloudXL", sf::Vector2f(608 + 800 * i, 48));
			Bg.addImageObj("cloudXXL", sf::Vector2f(450 + 800 * i, 20));
			Bg.addImageObj("shrubS", sf::Vector2f(384 + 770 * i, 186));
			Bg.addImageObj("shrubXL", sf::Vector2f(656 + 770 * i, 186));
			Bg.addImageObj("shrubXXL", sf::Vector2f(185 + 770 * i, 186));
			Bg.addImageObj("holm", sf::Vector2f(0 + 775 * i, 175));
			Bg.addImageObj("holm", sf::Vector2f(256 + 770 * i, 190));
		}
		Bg.addImageObj("castle", sf::Vector2f(3219,105));
		Bg.SetBgColor(sf::Color(100, 100, 255));		
		break;
	case 0:
		map.loadFromFile("sourses/levels/level_Bonus.txt", TileMap);
		Bg.SetBgColor(sf::Color::Black);
		Bg.addTextObj(15, "The money has not been realized,", sf::Vector2f(30, 60));
		Bg.addTextObj(15, "but the account now has + 19 coins", sf::Vector2f(30, 70));
		break;
	}

	
}

void level_Bonus(sf::RenderWindow& window, int& lives, GameMap& map, background& Bg, Interface& interface, std::map<char, Tile>& TileMap, bool& isBonusLevel) {
	int level = 0;
	interface.changeLevel("???");
	Person Player("sourses/sprites/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(80, 144), 4, 15, 0.005);
	Player.createJump("sourses/sprites/Mario_tileset.png");
	Player.setEntityHitboxLeft(20);
	Player.setEntityHitboxTop(40);
	Player.clearOffSet();
	interface.increaceMoney(19);
	level_init(level, Bg, map, TileMap);
	sf::Event event;
	sf::Clock clock;
	while (window.isOpen())
	{
		interface.updateTime(clock.getElapsedTime().asSeconds());
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;

		if (time > 20)
			time = 20;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Player.getEntityHitbox().left > 224 && Player.getEntityHitbox().top > 176) {
			//isBonusLevel = false;
			return;
		}
		if (Player.getLife() == true) {
			Player.move();
			Player.update(time, map, interface);
			Player.isEdgeOfMap(window.getSize().x);
		}

		Bg.drawBackground(window, Player.getOffsetX());
		Player.draw(window);
		map.DrawMap(window, Player.getOffsetX());
		interface.draw(window);
		window.display();
	}
}



void level_1(sf::RenderWindow& window, int& lives, GameMap& map, background& Bg, Interface& interface, std::map<char, Tile>& TileMap, bool& isLevelPassed,bool& isBonusLevel) {
	int level = 1;
	interface.RestartScore();
	interface.RestartTime();
	interface.changeLevel("1-1");
	Person Player("sourses/sprites/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(80, 144), 4, 15, 0.005);
	Player.createJump("sourses/sprites/Mario_tileset.png");
	if (!isBonusLevel) {
		Player.setEntityHitboxLeft(100);
		Player.setEntityHitboxTop(180);
		Player.clearOffSet();
	}
	else {
		Player.setEntityHitboxLeft(2608);
		Player.setEntityHitboxTop(176);
	}
	level_init(level, Bg, map, TileMap);
	const int countOfBonusMushroom = 1;
	BonusMushroom bonuses[countOfBonusMushroom]{
		BonusMushroom("sourses/sprites/Mario_tileset.png", 0.0005, sf::FloatRect(384, 160, 16, 16))
	};

	const int countOfTurtles = 1;
	Turtle turtle[countOfTurtles]{ 
		Turtle("sourses/sprites/Turtle.png", 0.05, sf::FloatRect(1728, 200, 16, 26), 0.0005, 0.27) 
	};

	const int countOfGumbas = 16;
	Gumba gumba[countOfGumbas]
	{
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(368, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(688, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1328, 64, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1360, 64, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1568, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1600, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1840, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(1864, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2000, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2016, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2048, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2064, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2816, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2000, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2688, 200, 16, 16), 0.0005),
		Gumba("sourses/sprites/Mario_tileset.png", 0.05, sf::FloatRect(2800, 176, 16, 16), 0.0005)
	};
	for (int i = 0; i < countOfBonusMushroom; i++) 
		bonuses[i].setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(0, 0), 3, 2, 0.005);
	for (int i = 0; i < countOfGumbas; i++) 
			gumba[i].setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(0, 0), 3, 2, 0.005);
	for (int i = 0; i < countOfTurtles; i++)		
			turtle[i].setAnimationSettings(sf::Vector2i(17, 27), sf::Vector2i(387, 239), 3, 0, 0.005);
	
	
	/*sf::Music music;
	music.openFromFile("sourses/sounds/moonlight.ogg");
	music.setLoop(true);
	music.setVolume(30);
	music.play();
	static sf::Music death;
	death.openFromFile("sourses/sounds/death1.ogg");
	death.setLoop(false);
	death.setVolume(30);
	death.play();
	static sf::Music LastDeath;
	LastDeath.openFromFile("sourses/sounds/LastlifeLost.ogg");
	LastDeath.setLoop(false);
	LastDeath.setVolume(30);*/
	sf::Font font;
	sf::Clock clock;
	bool Islevel = true;
	bool isTriggered = false;
	bool isFirsttime = true;
	sf::Event event;
	while (window.isOpen())
	{
		interface.updateTime(clock.getElapsedTime().asSeconds());
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;

		if (time > 20)
			time = 20;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Down)
				if (Player.getEntityHitbox().left > 912 && Player.getEntityHitbox().left < 928) {
					isBonusLevel = true;
					return;
				}
		}
		if (Player.getEntityHitbox().left > 3260 && Player.getEntityHitbox().top > 176) {
			isLevelPassed = true;
			return;
		}
		if (Player.getLife() !=0 ) {
			Player.move();
			Player.update(time, map, interface);
			Player.isEdgeOfMap(window.getSize().x);
			for (int i = 0; i < countOfBonusMushroom; i++) {
				bonuses[i].Death(Player, interface);
				bonuses[i].move(map);
				bonuses[i].update(time, Player);
			}
			for (int i = 0; i < countOfGumbas; i++) {
				gumba[i].move(map);
				gumba[i].update(time, Player);
				gumba[i].Death(Player, interface);
			}
			for (int i = 0; i < countOfTurtles; i++) {
				turtle[i].move(map);
				turtle[i].update(time, Player);
				turtle[i].Death(Player, interface);
			}
			//if (lives > 1)
			//	//death.play();
			//else
			//{
			//	death.stop();
			//	LastDeath.play();
			//}
		}
		else {
			//music.stop();
			if (Player.Death(240)) {
				lives--;
				Player.setLife(true);
				isLevelPassed = false;
				return;
			}
		}
		
		Bg.drawBackground(window, Player.getOffsetX());
		map.DrawMap(window, Player.getOffsetX());
		for (int i = 0; i < countOfBonusMushroom; i++)
			bonuses[i].draw(window);
		for (int i = 0; i < countOfGumbas; i++)
			gumba[i].draw(window);
		for (int i = 0; i < countOfTurtles; i++)
			turtle[i].draw(window);
		Player.draw(window);
		interface.draw(window);
		window.display();
	}
}




int main()
{
	sf::Vector2i windowSize(400,240);
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "Fuk yea!");
	window.setFramerateLimit(60);
	int lives = 3;
	background Bg("sourses/fonts/19783.ttf");
	GameMap map(240, 17);	
	Interface interface("sourses/fonts/19783.ttf");
	InterfaceInit(interface);
	Tile GBricks(sf::Vector2i(16, 16), 1, "sourses/sprites/greenbrick.png");
	Tile GStone(sf::Vector2i(16, 16), 1, "sourses/sprites/greenstone.png");
	Tile Bricks(sf::Vector2i(16,16), 1, "sourses/sprites/bricks.png",0,1);
	Tile Block(sf::Vector2i(16, 16), 1, "sourses/sprites/block.png");
	Tile OStone(sf::Vector2i(16, 16), 1, "sourses/sprites/orangestone.png");
	Tile invOStone(sf::Vector2i(16, 16), 0, "sourses/sprites/orangestone.png");
	Tile GPTL(sf::Vector2i(16, 16), 1, "sourses/sprites/tubeTopLeft.png");
	Tile GPL(sf::Vector2i(16, 16), 1, "sourses/sprites/tubeLeft.png");
	Tile GPTR(sf::Vector2i(16, 16), 1, "sourses/sprites/tubeTopRight.png");
	Tile GPR(sf::Vector2i(16, 16), 1, "sourses/sprites/tubeRight.png");
	Tile TubeUp(sf::Vector2i(16, 16), 1, "sourses/sprites/TubeUp.png");
	Tile TubeDown(sf::Vector2i(16, 16), 0, "sourses/sprites/tubeDown.png");
	Tile TubeTopUp(sf::Vector2i(16, 16), 1, "sourses/sprites/TubeTopUp.png");
	Tile TubeTopDown(sf::Vector2i(16, 16), 0, "sourses/sprites/TubeTopDown.png");
	Tile GPTC(sf::Vector2i(16, 16), 1, "sourses/sprites/grassplatformTopCenter.png");
	Tile GPC(sf::Vector2i(16, 16), 1, "sourses/sprites/grassplatformCenter.png");
	Tile FreeSpace(sf::Vector2i(16, 16), 1, "sourses/sprites/freespace.png");
	Tile Question(sf::Vector2i(16, 16), 1, "sourses/sprites/question.png", 0, 0, 1);
	Tile mQuestion(sf::Vector2i(16, 16), 1, "sourses/sprites/question.png", 0, 0, 0, 1);
	Tile DeathBlock(sf::Vector2i(16, 16), 1, "sourses/sprites/freespace.png", 1);
	std::map<char, Tile> TileMap ={ {' ', Tile()},
	{'d', DeathBlock},
	{'g', GBricks},
	{'G', GStone},
	{'b', Bricks},
	{'P', Block},
	{'s', OStone},
	{'S', invOStone},
	{'L', GPTL},
	{'l', GPL},
	{'R', GPTR},
	{'r', GPR},
	{'Z', TubeTopUp},
	{'X', TubeTopDown},
	{'z', TubeUp},
	{'x', TubeDown},
	{'C', GPTC},
	{'c', GPC},
	{'0', FreeSpace},
	{'q', Question},
	{'Q', mQuestion}
	};
	bool isLevelPassed_1 = false;
	bool isBonusLevel = false;
	bool isTriggered = false;
	MainMenu(window);
	while (window.isOpen())
	{
		if (lives) {
			BlackScreen(window, lives, 50);
			level_1(window, lives, map, Bg, interface, TileMap, isLevelPassed_1, isBonusLevel);
			if (isLevelPassed_1){
				WinScreen(window);
				isLevelPassed_1 = false;
			}
			if (isBonusLevel && !isTriggered)
			{
				BlackScreen(window, lives, 50);
				level_Bonus(window, lives, map,Bg, interface,TileMap,isBonusLevel);
				isTriggered = true;
			}
		}
		else
		{
			LoseScreen(window, 1800);
			MainMenu(window);
			lives = 3;
			isLevelPassed_1 = false;
		}

	}
    return 0;
}
