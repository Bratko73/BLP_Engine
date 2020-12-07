#pragma once
#include "Person.h"
#include "Animation.h"
#include "Interface.h"

class Enemy {
	sf::Vector2f coordinates;
	sf::FloatRect rectangle;
	bool life;
	Animation animation;
	bool onGround;
	float gravitation;
	std::string name;
	float heightOfJump;
public:
	Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle, float gravitation, const std::string name, float heightOfJump);
	void update(float time, Person& p);
	void move(Enemy& n);
	bool Death(Person& p, Interface& i);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);

	float& getX();
	float& getY();
	sf::Sprite getSprite();
	float getRectangleLeft();
	float getRectangleTop();
	float getRectangleHeight();
	float getRectangleWidth();
	std::string getName();

	void setRectangleLeft(float left);
	void setRectangleTop(float top);
	void setOnGround(bool val);
};
