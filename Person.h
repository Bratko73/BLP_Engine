#pragma once
#include <SFML/Graphics.hpp>
class Person
{
private:
	bool left_pressed;
	bool right_pressed;
	bool down_pressed;
	bool upper_pressed;

	bool gravitationCheck; //в будующем планируется сделать массив со всеми остальными параметрами
	float dx;
	float dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	float currentFrame;
	//Необходима доработка класса, данная часть кода - набросок.
public:
	Person();
	Person(std::string pathToFile);
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	void Jump();
	void update(float time);
	void Collision(int flag);
	//подумать самим или спросить преподователя, про то, где должна лежать Collision
};

