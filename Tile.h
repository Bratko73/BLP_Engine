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
	bool bonus;
	bool money;
public:
	Tile();
	Tile(sf::Vector2i size, bool hardness, std::string path_to_texture, bool lethality = 0, bool breakable = 0, bool bonus = 0, bool money = 0);
	Tile(sf::Vector2i size, std::string path_to_texture);
	Tile(const Tile& obj);
	~Tile();
	bool& GetLethality();
	bool& GetBreakable();
	bool& IsBonus();
	bool& isMoney();
	void setMoney(bool money);
	void SetBrick(std::string path_to_texture);
	sf::Sprite& Get_Sprite();
	void Set_Position(float xPos, float yPos);
	bool& Get_Hardness();
	void setSprite(std::string path);
};

