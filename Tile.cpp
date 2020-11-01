#include "Tile.h"
Tile::Tile()
{
	hardness = 0;
	SizeOfTile.x = 0;
	SizeOfTile.y = 0;
	PathToTexture = nullptr;
}

Tile::Tile(bool hardness, std::string path_to_texture, unsigned int x, unsigned int y)
{
	this->SizeOfTile.x = x;
	this->SizeOfTile.y = y;
	this->hardness = hardness;
	PathToTexture = path_to_texture;
	this->texture.loadFromFile(PathToTexture);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->SizeOfTile.x, this->SizeOfTile.y));
}

Tile::Tile(bool hardness, std::string path_to_texture, sf::Vector2u size)
{
	this->SizeOfTile.x = size.x;
	this->SizeOfTile.y = size.y;
	this->hardness = hardness;
	PathToTexture = path_to_texture;
	this->texture.loadFromFile(PathToTexture);
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->SizeOfTile.x, this->SizeOfTile.y));
}

Tile::Tile(const Tile& obj)
{
	this->SizeOfTile.x = obj.SizeOfTile.x;
	this->SizeOfTile.y = obj.SizeOfTile.y;
	this->hardness = obj.hardness;
	this->PathToTexture = obj.PathToTexture;
}

sf::Sprite Tile::Get_Sprite()
{
	return sprite;
}

/*void Tile::Set_Position(float xPos, float yPos)
{
	this->sprite.setPosition(xPos, yPos);
}

void Tile::Set_Position(sf::Vector2f Pos)
{
	this->sprite.setPosition(Pos);
}
*/

