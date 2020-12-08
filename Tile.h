#pragma once
#include "SFML/Graphics.hpp"
class Tile
{
protected:
	bool hardness;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2i SizeOfTile;
	std::string PathToTexture;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture);
	Tile(const Tile& obj);
	sf::Sprite& Get_Sprite();
	void Set_Position(float xPos, float yPos);
};

