#include "GameMap.h"
#include "assert.h"
GameMap::GameMap(unsigned int x,unsigned int y)
{
	m_x = x;
	m_y = y;
	Map = new Tile* [m_x];
	for (int i = 0; i < m_x; i++)
	{
		Map[i] = new Tile [m_y];
		for (int j = 0; j < m_y; j++)
		{
			Map[i][j] = Tile();
		}
	}
}

GameMap::~GameMap()
{
	for (int i = 0; i < m_x; i++)
	{
		delete[] Map[i];
	}
	delete Map;
}

void GameMap::SetCell(unsigned int x,unsigned int y, Tile tile)
{
	assert(x < m_x&& y < m_y);
	Map[x][y] = tile;
}

const Tile& GameMap::GetCell(unsigned int x, unsigned int y)
{
	assert(x < m_x&& y < m_y);
	return Map[x][y];
}

void GameMap::ClearMap(Tile tile = Tile())
{
	for (int i = 0; i < m_x; i++)
	{
		for (int j = 0; j < m_y; j++)
		{
			Map[i][j] = tile;
		}
	}
}

const int& GameMap::GetSizeX()
{
	return m_x;
}

const int& GameMap::GetSizeY()
{
	return m_y;
}

void GameMap::CreateRect(unsigned int x1, unsigned int y1, unsigned int widht, unsigned int height, Tile tile)
{
	for (int i = x1; i < widht + x1; i++)
	{
		for (int j = y1; j < y1 + height; j++)
		{
			SetCell(i, j, tile);
		}
	}

}
//TODO: DrawMap, LoadToFile, LoadFromString, LoadFromFile, PathToTexture in Tile.h and Tile.cpp