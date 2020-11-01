#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	bool gravitationCheck; //в будующем планируется сделать массив со всеми остальными параметрами
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	//Animation animation;
	sf::Sprite sprite;
	//Необходима доработка класса, данная часть кода - набросок.
public:
	Person();
	Person(std::string pathToFile);
	void move();
	void update(float time);
	// пока не добавили модуль коллизий пусть лежит тут
	//void Collision(int flag);
};

