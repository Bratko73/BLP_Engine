#include "FileSystem.h"

FileSystem::FileSystem(std::string path)
{
	this->path = path;
}

void FileSystem::changeFile(std::string newPath)
{
	this->path = newPath;
}

void FileSystem::loadLevel(Person& Player, std::vector <Gumba>& gumbas, std::vector <Turtle>& turtle, std::vector <BonusMushroom>& bonus, std::vector <Tile>& tiles, background& bg, std::map <char, Tile>& tileMap, GameMap& map)
{
	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open())
		return;
	else
	{
		//while (!fin.eof())
		//{
			std::string tmp;
			fin >> tmp;
			if (tmp == "Player")
			{
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				float gravity;
				fin >> gravity;
				float heightOfJump;
				fin >> heightOfJump;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				fin >> coordX;
				fin >> coordY;
				Player = Person(speed, gravity, heightOfJump, sf::FloatRect(coordX, coordY, sizeX, sizeY));
				Player.setAnimationSettings(sf::Vector2i(sizeX, sizeY), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames,rangeBetweenFrames, animationSpeed);
				Player.setSpriteSheet(pathToSprite);
			}
			fin >> tmp;
			if (tmp == "Gumba")
			{
				gumbas.clear();
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				float gravity;
				fin >> gravity;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;  
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					gumbas.push_back(Gumba(speed, sf::FloatRect(coordX, coordY, sizeX, sizeY), gravity));
					gumbas[i].setAnimationSettings(sf::Vector2i(sizeX, sizeY), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
					gumbas[i].setSpriteSheet(pathToSprite);
				}
			}
			fin >> tmp;
			if (tmp == "Turtle")
			{
				turtle.clear();
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				float gravity;
				fin >> gravity;
				float jump;
				fin >> jump;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					turtle.push_back(Turtle(speed, sf::FloatRect(coordX, coordY, sizeX, sizeY), gravity, jump));
					turtle[i].setAnimationSettings(sf::Vector2i(sizeX, sizeY), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
					turtle[i].setSpriteSheet(pathToSprite);
				}
			}
			fin >> tmp;
			if (tmp == "Bonus")
			{
				bonus.clear();
				int count;
				fin >> count;
				std::string pathToSprite;
				fin >> pathToSprite;
				float speed;
				fin >> speed;
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				float gravity;
				fin >> gravity;
				int countOfFrames;
				fin >> countOfFrames;
				int firstFrameX;
				fin >> firstFrameX;
				int firstFrameY;
				fin >> firstFrameY;
				int rangeBetweenFrames;
				fin >> rangeBetweenFrames;
				float animationSpeed;
				fin >> animationSpeed;
				int coordX;//Pizdec.txt
				int coordY;
				for (int i = 0; i < count; i++)
				{
					fin >> coordX;
					fin >> coordY;
					bonus.push_back(BonusMushroom(gravity, sf::FloatRect(coordX, coordY, sizeX, sizeY), speed));
				    bonus[i].setAnimationSettings(sf::Vector2i(sizeX, sizeY), sf::Vector2i(firstFrameX, firstFrameY), countOfFrames, rangeBetweenFrames, animationSpeed);
					bonus[i].setSpriteSheet(pathToSprite);
				}
			}
			fin >> tmp;
			if (tmp == "Bg")
			{
				bg.clearBg();
				bg.clearOffSet();
				bg.SetBgColor(sf::Color(100, 100, 255));
				fin >> tmp;
				if (tmp == "Textures")
				{
					int kinds;
					fin >> kinds;
					for (int i = 0; i < kinds; i++)
					{
						int count;
						fin >> count;
						std::string pathToTexture;
						fin >> pathToTexture;
						bg.addTexture(std::to_string(i), pathToTexture);
						for (int j = 0; j < count; j++)
						{
							int coordX;
							fin >> coordX;
							int coordY;
							fin >> coordY;
							bg.addImageObj(std::to_string(i), sf::Vector2f(coordX, coordY));
						}

					}
				}
			}
			fin >> tmp;
			if (tmp == "tileMap")
			{
				//sf::Vector2i size, bool hardness, std::string path_to_texture, bool lethality, bool breakable, bool bonus, bool money
				tileMap.clear();
				tiles.clear();
				int count;
				fin >> count;
				for (int i = 0; i < count; i++) 
				{
					char symbol;
					fin >> symbol;
					int size;
					fin >> size;
					bool hardness;
					fin >> hardness;
					std::string pathToTexture;
					fin >> pathToTexture;
					bool lethality;
					fin >> lethality;
					bool breakable;
					fin >> breakable;
					bool bonus;
					fin >> bonus;
					bool money;
					fin >> money;
					tiles.push_back(Tile(sf::Vector2i(size, size), hardness, pathToTexture, lethality, breakable, bonus, money));
					tiles[i].setSprite(pathToTexture);
					tileMap.insert(std::pair<char,Tile>(symbol, tiles[i]));
					
				}
				tileMap.insert(std::pair<char, Tile>(' ', Tile()));
			}
			fin >> tmp;
			if (tmp == "gameMap")
			{
				int sizeX;
				fin >> sizeX;
				int sizeY;
				fin >> sizeY;
				std::string path;
				fin >> path;
				//map = GameMap(sf::Vector2i(sizeX, sizeY));
				map.loadFromFile(path, tileMap);
			}

		//}
	}
}
