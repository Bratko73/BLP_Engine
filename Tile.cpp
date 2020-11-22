#include "Tile.h"

Tile::Tile(std::string path)
{
	if (!path.empty())
		this->FilePath = path;
	else
		this->FilePath = "0";
	this->TileSize = sf::Vector2i(16, 16);
	this->StartPos = sf::Vector2i(0, 0);
	this->Texture.loadFromFile(this->FilePath);
	this->Sprite.setTextureRect(sf::IntRect(StartPos, TileSize));
}

Tile::Tile()
{
	FilePath = "0";
	this->TileSize = sf::Vector2i(16, 16);
	this->StartPos = sf::Vector2i(0, 0);
}

