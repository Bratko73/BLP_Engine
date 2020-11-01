#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	sf::Vector2f offset;
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	Animation animation;
	sf::Sprite sprite;
	//Необходима доработка класса, данная часть кода - набросок.
public:
	Person();
	Person(std::string pathToFile);
	void move();
	void update(float time);
	float getX();
	float getY();
	float getOffsetX();
	float getOffsetY();
	void setOffsetX(float x);
	// пока не добавили модуль коллизий пусть лежит тут
	//void Collision(int flag);
};

