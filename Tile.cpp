#include "Tile.h"

Tile::Tile()
{
	size_x = 0;
	size_y = 0;
	hardness = 0;
	//TexturePath = nullptr;
}

Tile::Tile(unsigned int size_x, unsigned int size_y, bool hardness, std::string path_to_texture)
{
	this->size_x = size_x;
	this->size_y = size_y;
	this->hardness = hardness;
	//TexturePath = path_to_texture;
	sf::Texture texture;
	texture.loadFromFile(path_to_texture);
	this->sprite.setTexture(texture);

}

Tile::Tile(const Tile& obj)
{
	size_x = obj.size_x;
	size_y = obj.size_y;
	hardness = obj.hardness;
}


