#include "Tile.h"

Tile::Tile()
{
	hardness = 0;
}

Tile::Tile(bool hardness, std::string path_to_texture)
{
	this->hardness = hardness;
	sf::Texture texture;
	texture.loadFromFile(path_to_texture);
	this->sprite.setTexture(texture);

}

Tile::Tile(const Tile& obj)
{
	hardness = obj.hardness;
}

sf::Sprite Tile::Get_Sprite()
{
	return sprite;
}


