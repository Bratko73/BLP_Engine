#pragma once
#include "SFML/include/SFML/Graphics.hpp"
#include "Interface.h"
#include "Animation.h"
#include"GameMap.h"
#include"Person.h"
#include "TestMap.h"
#include "Enemy.h"
#include "Menu.h"
#include <vector>
#include <map>

class GameMario
{
public:
	GameMario(int lives);
	void init();
	void start(sf::RenderWindow& window);
	void loadLevel(std::string pathToLevel);
	void play(sf::RenderWindow& window);

private:
	sf::Clock clock;
	int lives;
	Interface interface;
	int level;
	//std::vector<Enemy> enemies;
	//Person Player;
	//GameMap map;
};

