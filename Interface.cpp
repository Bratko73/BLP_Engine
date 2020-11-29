#include "Interface.h"

Interface::Interface()
{
	this->score = score;
	this->time = time;
	this->money = money;
	this->level = level;
	this->countOfSprites = 0;
}

Interface::Interface(int score, int time, int money, int level)
{
	this->score = score;
	this->time = time;
	this->money = money;
	this->level = level;
}

Interface::~Interface()
{
	delete[] textures;
	delete[] sprites;
}

void Interface::addElem(std::string pathToFile)
{
	textures[countOfSprites];
}

void Interface::increaceScore(int scoreIncrement)
{
	this->score += scoreIncrement;
}

void Interface::setSpritePosition(int item, sf::Vector2f Position)
{
	item--;
	if (item < this->countOfSprites || item >= 0)
	{
		sprites[item].setPosition(Position);
	}
	else
		return;
}

void Interface::draw(sf::RenderWindow& window)
{
}
