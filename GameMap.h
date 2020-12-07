#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Tile.h"
#include <map>

class GameMap
{
private:
	Tile** Map;
	int x_size;
	int y_size;
	sf::Texture Background;
public:
	GameMap(sf::Vector2i size, std::string PathToBackground);
	void loadFromFile(const std::string &filePath, std::map<char, Tile> dictionary);
	void SetCell(int x, int y, Tile& tile);
	void ReadFromFile(std::string path, std::map<char, Tile> dictionary);
};


