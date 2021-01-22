#pragma once
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "GameMap.h"
#include "Person.h"
#include "Gumba.h"
#include "Turtle.h"
#include "background.h"
#include "BonusMushroom.h"

class FileSystem
{
	std::string path;
public:
	FileSystem(std::string path);
	void changeFile(std::string newPath);
	void loadLevel(Person& Player,std::vector <Gumba>& gumbas, std::vector <Turtle>& turtle, std::vector <BonusMushroom>& bonus, std::vector <Tile>& tiles, background& bg, std::map <char, Tile>& tileMap, GameMap& map);
};

