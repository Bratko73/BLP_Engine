#pragma once
#include "SFML/include/SFML/Graphics.hpp"
class Tile
{
protected:
	bool hardness;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u SizeOfTile;
	std::string PathToTexture;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture, unsigned int x, unsigned int y);
	Tile(bool hardness, std::string path_to_texture, sf::Vector2u size);
	Tile(const Tile& obj);
	sf::Sprite Get_Sprite();
	/*void Set_Position(float xPos, float yPos);
	void Set_Position(sf::Vector2f Pos);*/
};

