#include "GameMap.h"
#include "assert.h"
#include <fstream>
GameMap::GameMap()
{
	Size = sf::Vector2i(0, 0);
	Map = NULL;
}
GameMap::GameMap(unsigned int x, unsigned int y)
{
	Size.x = x;
	Size.y = y;
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

GameMap::GameMap(sf::Vector2i size)
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

GameMap::GameMap(const GameMap& obj)
{
	this->Size = obj.Size;
	this->Map = obj.Map;	
}

GameMap::~GameMap()
{

	for (int i = 0; i < Size.x; i++)
	{
		delete[] Map[i];
	}
	delete[] Map;
}

void GameMap::SetCell(unsigned int x, unsigned int y, Tile tile)
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

const int GameMap::GetSizeX()
{
	return Size.x;
}

const int GameMap::GetSizeY()
{
	return Size.y;
}

const sf::FloatRect& GameMap::GetTilePos(int x_xoord, int y_coord)
{
	return sf::FloatRect(Map[x_xoord][y_coord].Get_Sprite().getPosition(), sf::Vector2f(16,16));
}

bool GameMap::IsBonus(int x_coord, int y_coord)
{
	return Map[x_coord][y_coord].IsBonus();
}

bool GameMap::isMoney(int x_coord, int y_coord)
{
	return Map[x_coord][y_coord].isMoney();
}

void GameMap::setMoney(int x_coord, int y_coord, bool money)
{
	Map[x_coord][y_coord].setMoney(money);
}

bool GameMap::GetLethality(int x_coord, int y_coord)
{
	return Map[x_coord][y_coord].GetLethality();
}

bool GameMap::GetBreakable(int x_coord, int y_coord)
{
	return Map[x_coord][y_coord].GetBreakable();
}

void GameMap::SetEmptySpace(int x_coord, int y_coord)
{
	Map[x_coord][y_coord] = Tile();
}

void GameMap::SetBrick(int x_coord, int y_coord)
{
	Map[x_coord][y_coord].SetBrick("sourses/sprites/questionUsed.png");
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

void GameMap::DrawMap(sf::RenderWindow& window, float a)
{
	if (this->Map != nullptr)
	{
		for (int i = 0; i < Size.x; ++i)
		{
			for (int j = 0; j < Size.y; ++j)
			{
				Map[i][j].Set_Position(i * 16 - a, j * 16);
				window.draw(Map[i][j].Get_Sprite());
			}
		}
	}
	else
		throw std::runtime_error("Empty map");
}
void GameMap::loadFromFile(const std::string& filePath, std::map<char, Tile>& dictionary)
{
	std::ifstream file;

	file.open(filePath);

	if (!file.is_open())
		throw std::runtime_error("Can't load file: " + filePath);


	std::string str;
	for (int y = 0; y < this->Size.y; ++y)
	{
		std::getline(file, str);
		if (str.length() == Size.x)
		{
			for (int x = 0; x < Size.x; ++x)
			{
				assert(dictionary.find(str[x]) != dictionary.end());
				Map[x][y] = dictionary[str[x]];
				Map[x][y].Set_Position(float(x) * 16, float(y) * 16);
			}
		}
	}
}

bool GameMap::get_Hardness(int x_coord, int y_coord)
{
	return Map[x_coord][y_coord].Get_Hardness();
}



