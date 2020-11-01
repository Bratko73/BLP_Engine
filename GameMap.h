#pragma once
#include "Tile.h"
class GameMap
{
private:
	int m_x;
	int m_y;
	Tile** Map;
public:
	GameMap(unsigned int x, unsigned int y);
	~GameMap();
	void SetCell(unsigned int x,unsigned int y, Tile tile);
	const Tile& GetCell(unsigned int x, unsigned int y);
	void ClearMap(Tile tile = Tile());
	const int& GetSizeX();
	const int& GetSizeY();
	void CreateRect(unsigned int x1, unsigned int y1, unsigned int widht, unsigned int height, Tile tile);
	
};

