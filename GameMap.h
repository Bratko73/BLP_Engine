#pragma once
#include "Tile.h"
class GameMap
{
private:
	sf::Texture Background;
	sf::Vector2u Size;
	Tile** Map;
public:
	GameMap(unsigned int x, unsigned int y);
	GameMap(sf::Vector2u size);
	~GameMap();
	void SetCell(unsigned int x,unsigned int y, Tile tile);
	const Tile& GetCell(unsigned int x, unsigned int y);
	void ClearMap(Tile tile = Tile());
	const int& GetSizeX();
	const int& GetSizeY();
	void CreateRect(sf::Vector2u startCoord, sf::Vector2u sizeOfRect, Tile tile);
	void DrawMap(sf::RenderWindow& window);
};

