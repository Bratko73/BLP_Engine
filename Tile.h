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
	bool lethality = 0;
	bool breakable = 0;

public:
	Tile();
	Tile(sf::Vector2i size, bool hardness, std::string path_to_texture, bool lethality = 0, bool breakable = 0);
	Tile(sf::Vector2i size, std::string path_to_texture);
	Tile(std::string path_to_texture);
	Tile(const Tile& obj);
	~Tile();
	bool& GetLethality();
	bool& GetBreakable();
	sf::Sprite& Get_Sprite();
	void Set_Position(float xPos, float yPos);
	bool& Get_Hardness();
};

