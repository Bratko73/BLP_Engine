#pragma once
#include <SFML/Graphics.hpp>
#include <string>
//DOES NOT WORK!Leave HOPE everyone who enters here
class Interface
{
private:
	int score;
	int time;
	int money;
	int level;
	sf::Texture textures[9];
	sf::Sprite sprites[9];
	int countOfSprites;
public:
	Interface();
	Interface(int score, int time, int money, int level);
	~Interface();
	void addElem(std::string pathToFile);
	void increaceScore(int scoreIncrement);
	void setSpritePosition(int item, sf::Vector2f Position);
	void draw(sf::RenderWindow& window);
};

//DOES NOT WORK!Leave HOPE everyone who enters here
