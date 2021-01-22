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
#include "Collision.h"
#include "FileSystem.h"
#include <list>

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

void BlackScreen(sf::RenderWindow& window,int& lives, float time, bool& isBlackScreen) {
	background Bg("sourses/fonts/19783.ttf");
	Bg.addTextObj(15, "X", sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 - 5));
	Bg.addTextObj(30, std::to_string(lives), sf::Vector2f(window.getSize().x / 2 + 16, window.getSize().y / 2 - 16));
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Zefir", "sourses/sprites/zefir.png");
	Bg.addImageObj("Zefir", sf::Vector2f(window.getSize().x / 2 - 26, window.getSize().y / 2));
	sf::Clock clock;
	isBlackScreen = false;
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
	sf::Clock clock;
	background Bg("sourses/fonts/19783.ttf");
	Bg.SetBgColor(sf::Color::Black);
	Bg.addTexture("Tramp", "sourses/sprites/tramp.jpg");
	Bg.addImageObj("Tramp", sf::Vector2f(0, 0));


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

void WinScreen(sf::RenderWindow& window) {
	background Bg("sourses/fonts/19783.ttf");
	Bg.SetBgColor(sf::Color::Cyan);
	Bg.addTexture("Thanks", "sourses/sprites/Grazies.png");
	Bg.addImageObj("Thanks", sf::Vector2f(0, 0));
	sf::Music music;
	music.openFromFile("sourses/sounds/WhalShark.ogg");
	music.setLoop(true);
	music.setVolume(5);
	music.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Space)
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

/*
void level_Bonus(sf::RenderWindow& window, int& lives,  Interface& interface, std::map<char, Tile>& TileMap, bool& isBonusLevel) {
	GameMap map(240, 17);
	background Bg("sourses/fonts/19783.ttf");
	int level = 0;
	interface.changeLevel("???");
	Person Player("sourses/sprites/Mario_tileset.png", 0.1, 0.0005, 0.27, sf::FloatRect(100, 180, 16, 16));
	Player.setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(80, 144), 4, 15, 0.005);
	Player.createJump("sourses/sprites/Mario_tileset.png");
	Player.setEntityHitboxLeft(20);
	Player.setEntityHitboxTop(40);
	Player.clearOffSet();
	interface.increaceMoney(19);
	//level_init(level, Bg, map, TileMap);
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
		if (Player.getLife()) {
			Player.move();
			Player.update(time);
			Player.isEdgeOfMap(window.getSize().x);
		}

		Bg.drawBackground(window, Player.getOffsetX());
		Player.draw(window);
		map.DrawMap(window, Player.getOffsetX());
		interface.draw(window);
		window.display();
	}
}*/

void handleCollision(Person& player, BonusMushroom* bonus, Enemy* enemy, Interface& i) {
	const int tileSize = 16;
	const float MarioYvelocityAfterKill = -0.2;
	const int numberOfPointsPerKillTurtle = 15;
	const int numberOfPointsPerKillGumba = 10;
	const int numberOfPointsPerKillBonus = 100;
	const float shellSpeed = 0.15;
	if (enemy != NULL) {
		if (player.getEntityHitbox().intersects(enemy->getEntityHitbox()))
			if (enemy->getLife())
				if (player.getYvelocity() > 0) {
					if (enemy->getHeightOfJump() != 0) {
						player.setVelocity(player.getXvelocity(), MarioYvelocityAfterKill);
						if (enemy->getLife() == 11) {
							i.increaceScore(numberOfPointsPerKillTurtle);
							enemy->loseLife();
							enemy->setVelocity(0, enemy->getYvelocity());
						}
						else if (enemy->getLife() % 2 == 0) {
							enemy->loseLife();
							enemy->setVelocity(shellSpeed, enemy->getYvelocity());
						}
						else if (enemy->getLife() % 2 == 1) {
							enemy->loseLife();
							enemy->setVelocity(0, enemy->getYvelocity());
						}
					}
					else {
						player.setVelocity(player.getXvelocity(), MarioYvelocityAfterKill);
						i.increaceScore(numberOfPointsPerKillGumba);
						enemy->loseLife();
						enemy->setVelocity(0, enemy->getYvelocity());
					}
				}
				else {
					static int immortalTime = -1;
					if (player.getLife() == 2) {
						player.changeModel(1);
						immortalTime = 5;       //5 - число, которое хорошо подходит для бессмертия на 1 секунду
					}
					else
						if (immortalTime < 0)
							player.loseLife();
					immortalTime--;
				}
	}
				/*if (t.getEntityHitbox().intersects(Enemy::entityHitbox))
					if (life)
						if (t.getLife() == 1)
						{
							life--;
							velocity.x = 0;
						}*/
	if (bonus != NULL) {
		if (player.getEntityHitbox().intersects(bonus->getEntityHitbox()))
			if (bonus->getLife() == 2) {
				bonus->setEntityHitboxTop(bonus->getEntityHitbox().top - tileSize);
				bonus->setMushroomHitboxLeft(bonus->getEntityHitbox().left);
				bonus->setVelocity(bonus->getSpeed(), bonus->getYvelocity());
				bonus->loseLife();
			}
			else if (bonus->getLife() == 1) {
				i.increaceScore(numberOfPointsPerKillBonus);
				bonus->loseLife();
				bonus->setVelocity(0, bonus->getYvelocity());
				player.changeModel(2);
			}
	}
}

bool mapCollision(Entity* e, GameMap& map, bool flag, Interface& interface) {
	const int pixelsInTile = 16;
	for (int i = e->getEntityHitbox().top / pixelsInTile; i < (e->getEntityHitbox().top + e->getEntityHitbox().height) / pixelsInTile; i++)
		for (int j = e->getEntityHitbox().left / pixelsInTile; j < (e->getEntityHitbox().left + e->getEntityHitbox().width) / pixelsInTile; j++)
		{
			if (Collision::collision(e->getEntityHitbox(), map.GetTilePos(j, i)));
			{
				if (map.GetLethality(j, i))
					e->loseLife();
				if (map.get_Hardness(j, i))
				{
					if (e->getYvelocity() > 0 && flag == 1)
					{
						e->setEntityHitboxTop(i * pixelsInTile - e->getEntityHitbox().height);
						e->setVelocity(e->getXvelocity(), 0);
						e->setOnGround(true);
					}
					if (e->getYvelocity() < 0 && flag == 1)
					{
						if (map.GetBreakable(j, i))
							map.SetEmptySpace(j, i);
						e->setEntityHitboxTop(i * pixelsInTile + e->getEntityHitbox().height);
						e->setVelocity(e->getXvelocity(), 0);
						if (map.IsBonus(j, i) == true) {
							map.SetBrick(j, i);
						}
						if (map.isMoney(j, i) == true) {
							map.SetBrick(j, i);
							map.setMoney(j, i, false);
							interface.increaceMoney(1);
						}
					}
					if (e->getXvelocity() > 0 && flag == 0)
					{
						e->setEntityHitboxLeft(j * pixelsInTile - e->getEntityHitbox().width);
						e->setVelocity(e->getXvelocity() * (-1), e->getYvelocity());
						return true;
					}
					if (e->getXvelocity() < 0 && flag == 0)
					{
						e->setEntityHitboxLeft(j * pixelsInTile + e->getEntityHitbox().width);
						e->setVelocity(e->getXvelocity() * (-1), e->getYvelocity());
						return true;
					}
				}

			}
		}
	return false;
}

int main()
{
	sf::Vector2i windowSize(400,240);
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "Fuk yea!");
	window.setFramerateLimit(60);
	int lives = 3;
	int level = 1;
	Person Player;
	Interface interface("sourses/fonts/19783.ttf");
	InterfaceInit(interface);

	std::vector<Tile> tiles;
	std::map<char, Tile> tileMap;
	std::vector<Gumba> gumba;
	std::vector<Turtle> turtle;
	std::vector<BonusMushroom> bonus;
	background bg;
	GameMap map(240,17);
/*
	sf::Music music;
	music.openFromFile("sourses/sounds/moonlight.ogg");
	music.setLoop(true);
	music.setVolume(10);
	music.play();
	static sf::Music death;
	death.openFromFile("sourses/sounds/death1.ogg");
	death.setLoop(false);
	death.setVolume(20);
	death.play();
	static sf::Music LastDeath;
	LastDeath.openFromFile("sourses/sounds/LastlifeLost.ogg");
	LastDeath.setLoop(false);
	LastDeath.setVolume(10);
*/
	FileSystem fileSys(" ");

	sf::Font font;
	sf::Clock clock;
	bool Islevel = true;
	bool isTriggered = false;
	bool isFirsttime = true;
	bool isLevelPassed = false;
	bool isBonusLevel = false;
	bool isBlackScreen = true;
	bool reconfigLevel = true;
	bool isMainMenu = true;
	fileSys.changeFile("sourses/level_" + std::to_string(level) + "_sourses.txt");
	fileSys.loadLevel(Player, gumba, turtle, bonus, tiles, bg, tileMap, map);

	sf::Event event;
	while (window.isOpen())
	{
		if (reconfigLevel)
		{
			reconfigLevel = false;
			fileSys.changeFile("sourses/level_" + std::to_string(level) + "_sourses.txt");
			fileSys.loadLevel(Player,gumba, turtle, bonus, tiles, bg, tileMap, map);
		}
		if (lives > 0) {
			if (isMainMenu) {
				MainMenu(window);
				isMainMenu = false;
			}
			if (isBlackScreen)
				BlackScreen(window, lives, 50, isBlackScreen);
			interface.updateTime(clock.getElapsedTime().asSeconds());
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();

			time = time / 800;

			if (time > 20)
				time = 20;
			if (interface.getTime() == 0) {
				lives = 0;
				continue;
				}

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.key.code == sf::Keyboard::Down)
					if (Player.getEntityHitbox().left > 912 && Player.getEntityHitbox().left < 928) {
						isBonusLevel = true;
					}

			}
			if (Player.getEntityHitbox().left > 3260 && Player.getEntityHitbox().left < 3265 && Player.getEntityHitbox().top > 160) {
				isLevelPassed = true;
				continue;
			}

			if (Player.getLife() > 0) {
				//Player.move();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					Player.move(1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					Player.move(-1);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					Player.move(2);
				Player.setEntityHitboxLeft(Player.getEntityHitbox().left + Player.getXvelocity() * time);
				mapCollision(&Player, map, 0, interface);
				if (!Player.getOnGround())
					Player.setVelocity(Player.getXvelocity(), Player.getYvelocity() + Player.getGravitation() * time);
				Player.setEntityHitboxTop(Player.getEntityHitbox().top + Player.getYvelocity() * time);
				Player.setOnGround(false);
				mapCollision(&Player, map, 1, interface);
				Player.update(time);
				Player.isEdgeOfMap(window.getSize().x);
				for (int i = 0; i < bonus.size(); i++) {
					if (Collision::collision(Player.getEntityHitbox(), bonus[i].getEntityHitbox()))
						handleCollision(Player, &bonus[i], NULL, interface);
					bonus[i].update(time, Player);
					mapCollision(&bonus[i], map, 1, interface);
					mapCollision(&bonus[i], map, 0, interface);
				}
				for (int i = 0; i < gumba.size(); i++) {
					if (Collision::collision(Player.getEntityHitbox(), gumba[i].getEntityHitbox()))
						handleCollision(Player, NULL, &gumba[i], interface);
					gumba[i].move(map);
					gumba[i].update(time, Player);
					mapCollision(&gumba[i], map, 1, interface);
					mapCollision(&gumba[i], map, 0, interface);
				}
				for (int i = 0; i < turtle.size(); i++) {
					if (Collision::collision(Player.getEntityHitbox(), turtle[i].getEntityHitbox()))
						handleCollision(Player, NULL, &turtle[i], interface);
					turtle[i].move(map);
					turtle[i].update(time, Player);
					mapCollision(&turtle[i], map, 1, interface);
					mapCollision(&turtle[i], map, 0, interface);
				}
				//if (lives > 1)
				//	death.play();
				//else
				//{
				//	death.stop();
				//	LastDeath.play();
				//}
			}
			else {
				//music.stop();
				if (Player.death(window.getSize().y)) {
					lives--;
					reconfigLevel = true;
					isBlackScreen = true;
					interface.RestartMoney();
					interface.RestartScore();
					Player.increaseLife();
					isLevelPassed = false;
					continue;
				}
			}
			bg.drawBackground(window, Player.getOffsetX());
			map.DrawMap(window, Player.getOffsetX());
			for (int i = 0; i < bonus.size(); i++)
				bonus[i].draw(window);
			for (int i = 0; i < gumba.size(); i++)
				gumba[i].draw(window);
			for (int i = 0; i < turtle.size(); i++)
				turtle[i].draw(window);
			Player.draw(window);
			interface.draw(window);
			window.display();
			
			
			if (isLevelPassed) {
				WinScreen(window);
				isLevelPassed = false;
			}
			if (isBonusLevel && !isTriggered)
			{
				isBlackScreen = true;
				//reconfig level
				isTriggered = true;
			}
		}
		else
		{
			interface.RestartTime();
			LoseScreen(window, 50);
			isMainMenu = true;
			lives = 3;
			isLevelPassed = false;
		}

	}

    return 0;
}
