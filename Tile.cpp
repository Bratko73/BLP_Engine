#include "Tile.h"

Tile::Tile()
{
	hardness = 0;
	size_x = 0;
	size_y = 0;
}

Tile::Tile(bool hardness, std::string path_to_texture, int x, int y)
{
	this->size_x = x;
	this->size_y = y;
	this->hardness = hardness;
	this->texture.loadFromFile(path_to_texture);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->size_x, this->size_y));
}

Tile::Tile(const Tile& obj)
{
	this->size_x = obj.size_x;
	this->size_y = obj.size_y;
	this->hardness = obj.hardness;
}

sf::Sprite Tile::Get_Sprite()
{
	return sprite;
}

void Tile::Set_Position(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}

void Tile::Set_Position(sf::Vector2f Pos)
{
	this->sprite.setPosition(Pos);
}


