#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <map>
class GameMap
{
private:
	sf::Vector2i Size;
	Tile** Map;

public:
	GameMap();
	GameMap(unsigned int x, unsigned int y);
	GameMap(sf::Vector2i size);
	GameMap(const GameMap& obj);
	~GameMap();
	void SetCell(unsigned int x, unsigned int y, Tile tile);
	const Tile& GetCell(unsigned int x, unsigned int y);
	void ClearMap(Tile tile = Tile());
	const int& GetSizeX();
	const int& GetSizeY();
	const sf::Vector2f& GetTilePos(int x_xoord, int y_coord);
	bool& GetLethality(int x_coord, int y_coord);
	bool& GetBreakable(int x_coord, int y_coord);
	void SetEmptySpace(int x_coord, int y_coord);
	void CreateRect(sf::Vector2u startCoord, sf::Vector2u sizeOfRect, Tile tile);
	void DrawMap(sf::RenderWindow& window, float a);
	void loadFromFile(const std::string& filePath, std::map<char, Tile>& dictionary);
	bool& get_Hardness(int x_coord, int y_coord);
	
};

