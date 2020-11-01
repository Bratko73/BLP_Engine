#pragma once
#include "Tile.h"
class GameMap
{
private:
	int m_x;
	int m_y;
	Tile** Map;
public:
	GameMap(int x, int y);
	~GameMap();
	void SetCell(int x, int y, Tile tile);
	const Tile& GetCell(int x, int y);
	void ClearMap(Tile tile());
	const int& GetSizeX();
	const int& GetSizeY();
	
};

