#pragma once
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
protected:
	bool hardness;
	sf::Texture texture;
	sf::Sprite sprite;
	int size_x;
	int size_y;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture, int x, int y);
	Tile(const Tile& obj);
	sf::Sprite Get_Sprite();
	void Set_Position(float xPos, float yPos);
	void Set_Position(sf::Vector2f Pos);
};

