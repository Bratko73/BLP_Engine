#pragma once
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
protected:
	int size_x;
	int size_y;
	bool hardness;
	sf::Sprite sprite;
	//std::string TexturePath;
public:
	Tile();
	Tile(unsigned int size_x, unsigned int size_y, bool hardness, std::string path_to_texture);
	Tile(const Tile& obj);
};

