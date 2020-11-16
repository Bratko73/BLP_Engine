#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	float speed;
	sf::Vector2f offset;
	sf::Vector2f coordinates;
	sf::FloatRect rectangle;
	Animation animation;
	bool onGround;
	float gravitation;
	float heightOfJump;
public:
	Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect Rectangle);

	void move();
	void update(float time, Person& p);
	void isEdgeOfMap(const int screenWidth);
	void Death();

	float& getX();
	float& getY();
	float& getOffsetX();
	float& getOffsetY();
	float getRectangleLeft();
	float getRectangleTop();
	float getRectangleHeight();
	float getRectangleWidth();
	sf::Sprite getSprite();
	sf::FloatRect getRectangle();

	void setOnGround(bool val);
	void setRectangleLeft(float left);
	void setRectangleTop(float top);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
};

