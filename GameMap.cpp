#include "GameMap.h"
#include "assert.h"
#include <fstream>
GameMap::GameMap(unsigned int x,unsigned int y)
{
	Size.x = x;
	Size.y = y;

	Map = new Tile* [Size.x];
	for (int i = 0; i < Size.x; i++)
	{
		Map[i] = new Tile [Size.y];
		for (int j = 0; j < Size.y; j++)
		{
			Map[i][j] = Tile();
		}
	}
}

GameMap::GameMap(sf::Vector2u size)
{
	Size.x = size.x;
	Size.y = size.y;
	Map = new Tile * [Size.x];
	for (int i = 0; i < Size.x; i++)
	{
		Map[i] = new Tile[Size.y];
		for (int j = 0; j < Size.y; j++)
		{
			Map[i][j] = Tile();
		}
	}
}

GameMap::~GameMap()
{
	for (int i = 0; i < Size.x; i++)
	{
		delete[] Map[i];
	}
	delete Map;
}

void GameMap::SetCell(unsigned int x,unsigned int y, Tile tile)
{
	assert(x < Size.x&& y < Size.y);
	Map[x][y] = tile;
}

const Tile& GameMap::GetCell(unsigned int x, unsigned int y)
{
	assert(x < Size.x&& y < Size.y);
	return Map[x][y];
}

void GameMap::ClearMap(Tile tile)
{
	for (unsigned int i = 0; i < Size.x; i++)
	{
		for (unsigned int j = 0; j < Size.y; j++)
		{
			Map[i][j] = tile;
		}
	}
}

const int& GameMap::GetSizeX()
{
	return Size.x;
}

const int& GameMap::GetSizeY()
{
	return Size.y;
}

void GameMap::CreateRect(sf::Vector2u startCoord, sf::Vector2u sizeOfRect, Tile tile)
{
	for (unsigned int i = startCoord.x; i < sizeOfRect.x + startCoord.x; i++)
	{
		for (unsigned int j = startCoord.y; j < startCoord.y + sizeOfRect.y; j++)
		{
			SetCell(i, j, tile);
		}
	}
}

void GameMap::DrawMap(sf::RenderWindow& window)
{
	if (this->Map != nullptr)
	{
		for (int i = 0; i < Size.x; i++)
		{
			for (int j = 0; j < Size.y; j++)
			{
				window.draw(Map[i][j].Get_Sprite());
			}
		}
	}
	else
		throw std::runtime_error("Empty map");
}

//TODO: DrawMap, LoadToFile, LoadFromString, LoadFromFile, PathToTexture in Tile.h and Tile.cpp