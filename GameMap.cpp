#include "GameMap.h"
#include "assert.h"
#include <fstream>



//TODO: LoadToFile, LoadFromFile, PathToTexture in Tile.h and Tile.cpp

GameMap::GameMap(sf::Vector2f start, std::string TilefilePath, sf::Vector2f posInFile, sf::Window& window, sf::Vector2u tileSize)
{
	tile = Tile(posInFile, TilefilePath, tileSize);
	this->TileStartPos = start;
	this->MapSize.x = window.getSize().x / tile.Size.x;
	this->MapSize.y = window.getSize().y / tile.Size.y;
	
	this->Map = new Tile* [MapSize.x];
	for (int i = 0; i < MapSize.x; i++)
	{
		this->Map[i] = new Tile[this->MapSize.y];
		for (int j = 0; j < MapSize.y; j++)
		{
			this->Map[i][j] = tile;
		}
	}

	
}

void GameMap::CreateCell(unsigned int xPos, unsigned int yPos, Tile& tile)
{
	assert(xPos < MapSize.x&& yPos < MapSize.y);
	Map[xPos][yPos] = tile;
}

void GameMap::SetRect(sf::Vector2f start, sf::Vector2f size_of_rect)
{
	for (int i = start.x; i < size_of_rect.x + start.x; i++)
		for (int j = start.y; j < start.y + size_of_rect.y; j++)
			CreateCell(i, j, this->tile);
}

void GameMap::DrawMap(sf::RenderWindow& window)
{
	for (int i = 0; i < MapSize.x; i++)
	{
		for (int j = 0; j < MapSize.y; j ++)
		{
			window.draw(Map[i][j].GetSprite());
		}
	}
}
