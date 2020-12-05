#pragma once
#include <iostream>
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
private:
	std::string FilePath;
	sf::Vector2i TileSize;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Vector2i StartPos;
	bool hardness;
public:
	Tile(std::string path);
	Tile();
};

