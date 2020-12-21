#include "Tile.h"
#include <string>
#include <SFML/Graphics.hpp>
Tile::Tile()
{
	hardness = 0;
	SizeOfTile.x = 16;
	SizeOfTile.y = 16;
	PathToTexture = '0';
	lethality = false;
}

Tile::Tile(sf::Vector2i size, bool hardness, std::string path_to_texture, bool lethality, bool breakable, bool bonus)
{
	SizeOfTile.x = size.x;
	SizeOfTile.y = size.y;
	this->hardness = hardness;
	PathToTexture = path_to_texture;
	this->texture.loadFromFile(PathToTexture);
	this->sprite = sf::Sprite(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->SizeOfTile.x, this->SizeOfTile.y));
	this->lethality = lethality;
	this->breakable = breakable;
	this->bonus = bonus;
}

Tile::Tile(sf::Vector2i size, std::string path_to_texture)
{
	SizeOfTile.x = size.x;
	SizeOfTile.y = size.y;
	hardness = 0;
	PathToTexture = path_to_texture;
	texture.loadFromFile(PathToTexture);
	sprite = sf::Sprite(texture);
	lethality = 0;
	breakable = 0;
	bonus = 0;
}



Tile::Tile(const Tile& obj)
{
	this->SizeOfTile.x = obj.SizeOfTile.x;
	this->SizeOfTile.y = obj.SizeOfTile.y;
	this->hardness = obj.hardness;
	this->PathToTexture = obj.PathToTexture;
	this->texture = obj.texture;
	this->sprite = obj.sprite;
	this->lethality = obj.lethality;
	this->breakable = obj.breakable;
	this->bonus = obj.bonus;
}

Tile::~Tile()
{
}



bool& Tile::GetLethality()
{
	return this->lethality;
}

bool& Tile::GetBreakable()
{
	return this->breakable;
}

bool& Tile::IsBonus()
{
	return this->bonus;
}

void Tile::SetBrick(std::string path_to_texture)
{
	PathToTexture = path_to_texture;
	this->texture.loadFromFile(PathToTexture);
	this->sprite = sf::Sprite(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->SizeOfTile.x, this->SizeOfTile.y));
}

sf::Sprite& Tile::Get_Sprite()
{
	return this->sprite;
}

void Tile::Set_Position(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}
bool& Tile::Get_Hardness()
{
	return this->hardness;
}
