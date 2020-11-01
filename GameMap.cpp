#include "GameMap.h"

GameMap::GameMap(int x, int y)
{

}

GameMap::~GameMap()
{
}

void GameMap::SetCell(int x, int y, Tile tile)
{
}

const Tile& GameMap::GetCell(int x, int y)
{
	return Map[x][y];
}

void GameMap::ClearMap(Tile tile())
{
}

const int& GameMap::GetSizeX()
{
	return m_x;
}

const int& GameMap::GetSizeY()
{
	return m_y;
}
