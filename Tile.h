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
	bool lethality;
public:
	Tile();
	Tile(bool hardness, std::string path_to_texture, bool lethality = 0);
	Tile(const Tile& obj);
	~Tile();
	bool& GetLethality();
	sf::Sprite& Get_Sprite();
	void Set_Position(float xPos, float yPos);
	bool& Get_Hardness();
};

