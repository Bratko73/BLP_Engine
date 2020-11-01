#pragma once
#include "SFML/Graphics.hpp"
class GameMap
{
private:
	class Tile
	{
		public:
		sf::Vector2f TileFilePos;
		std::string PathToFile;
		sf::Vector2u Size;
		sf::Texture SprTexture;
		sf::Sprite TileSprite;
		Tile (sf::Vector2f pos_in_file, std::string PathToFile, sf::Vector2u size)
		{
			this->PathToFile = PathToFile;
			this->TileFilePos = pos_in_file;
			this->Size = size;
			SprTexture.loadFromFile(PathToFile);
			TileSprite.setTextureRect(sf::IntRect(TileFilePos.x, TileFilePos.y, Size.x, Size.y));
		}
		Tile()
		{
			this->TileFilePos = sf::Vector2f();
			this->PathToFile = "0";
		}
		sf::Sprite& GetSprite()
		{
			return this->TileSprite;
		}
		Tile(const Tile& obj)
		{
			this->PathToFile = obj.PathToFile;
			this->Size = obj.Size;
			this->SprTexture = obj.SprTexture;
			this->TileFilePos = obj.TileFilePos;
			this->TileSprite = obj.TileSprite;
		}
		Tile& operator = (const Tile obj)
		{
			this->PathToFile = obj.PathToFile;
			this->Size = obj.Size;
			this->SprTexture = obj.SprTexture;
			this->TileFilePos = obj.TileFilePos;
			this->TileSprite = obj.TileSprite;
			return *this;
		}
	};
	Tile tile;
	Tile** Map;
	sf::Vector2f MapSize;
	sf::Vector2f TileStartPos;
	sf::Vector2f TileCurrentPos;
public :
	GameMap(sf::Vector2f start, std::string TilefilePath, sf::Vector2f posInFile, sf::Window& window, sf::Vector2u tileSize);
	void CreateCell(unsigned int xPos, unsigned int yPos, Tile& tile);
	void SetRect(sf::Vector2f start, sf::Vector2f size);
	void DrawMap(sf::RenderWindow& window);
};


