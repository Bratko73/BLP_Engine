#include "GameMap.h"
#include "assert.h"
#include <fstream>

GameMap::GameMap(sf::Vector2i size, std::string PathToBackground)
{
	this->x_size = size.x/16;
	this->y_size = size.y/16;
	this->Background.loadFromFile(PathToBackground);
	this->Map = new Tile*[x_size];
	for (int i = 0; i < x_size; i++)
	{
		Map[i] = new Tile[y_size];
		for (int j = 0; j < y_size; j++)
		{
			this->Map[i][j] = Tile();
		}
	}
}

void GameMap::loadFromFile(const std::string& filePath, std::map<char, Tile> dictionary)
{
	std::ifstream file;

	file.open(filePath);

	if (!file.is_open())
		throw std::runtime_error("Can't load file: " + filePath);


	std::string str;
	for (int y = 0; y < this->y_size; ++y)
	{
		std::getline(file, str);
		if (str.length() == x_size);
		for (int x = 0; x < x_size; ++x)
		{
			assert(dictionary.find(str[x]) != dictionary.end());
			Map[x][y] = dictionary[str[x]];
		}
	}
}
void GameMap::SetCell(int x, int y, Tile& tile)
{
	if (x <= this->x_size && y <= this->y_size)
	{
		this->Map[x][y] = tile;
	}
}
