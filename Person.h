#pragma once
#include <SFML/Graphics.hpp>

class Person
{
private:
	bool gravitationCheck; //в будующем планируется сделать массив со всеми остальными параметрами
	float dx;
	float dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	//Необходима доработка класса, данная часть кода - набросок.
public:
	Person();
	Person(std::string pathToFile);
	// в каждый метод движения будет передаваться разрешённость этого движения
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	void Jump();
	void update(float time);
	// пока не добавили модуль коллизий пусть лежит тут
	//void Collision(int flag);
};

