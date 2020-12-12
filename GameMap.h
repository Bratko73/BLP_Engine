#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <map>
class GameMap
{
private:
	sf::Texture Background;
	sf::Vector2i Size;
	Tile** Map;
public:
	GameMap();
	GameMap(unsigned int x, unsigned int y);
	GameMap(sf::Vector2i size);
	~GameMap();
	void SetCell(unsigned int x, unsigned int y, Tile tile);
	const Tile& GetCell(unsigned int x, unsigned int y);
	void ClearMap(Tile tile = Tile());
	const int& GetSizeX();
	const int& GetSizeY();
	void CreateRect(sf::Vector2u startCoord, sf::Vector2u sizeOfRect, Tile tile);
	void DrawMap(sf::RenderWindow& window);
	void loadFromFile(const std::string& filePath, std::map<char, Tile>& dictionary);
};

