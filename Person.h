#pragma once
#include <SFML/Graphics.hpp>

class Person
{
private:
	bool left_pressed;
	bool right_pressed;
	bool down_pressed;
	bool upper_pressed;
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
	void Collision(int flag);
	//подумать самим или спросить преподователя, про то, где должна лежать Collision
};

