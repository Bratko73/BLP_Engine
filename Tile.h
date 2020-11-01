#pragma once
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
protected:
	bool hardness;
	sf::Sprite sprite;
	int size_x;
	int size_y;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture, int x, int y);
	Tile(const Tile& obj);
	sf::Sprite Get_Sprite();
};

