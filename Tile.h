#pragma once
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
protected:
	bool hardness;
	sf::Sprite sprite;
	//std::string TexturePath;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture);
	Tile(const Tile& obj);
	sf::Sprite Get_Sprite();
};

