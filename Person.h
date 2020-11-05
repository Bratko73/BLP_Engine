#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Person
{
private:
	float speed;
	sf::Vector2f offset;
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool onGround;
	Animation animation;
	float gravitation;
	float heightOfJump;
public:
	Person();
	Person(std::string pathToFile, float speed, float gravitation, float heightOfJump, sf::FloatRect rect);

	void move();
	void update(float time, Person& p);


	float& getX();
	float& getY();
	float& getOffsetX();
	float& getOffsetY();
	float getRectLeft();
	float getRectTop();
	float getRectHeight();
	float getRectWidth();
	bool getOnGround();
	sf::Sprite getSprite();

	void setOffsetX(float x);
	void setOffsetY(float y);
	void setOnGround(bool val);
	void setRectLeft(float left);
	void setRectTop(float top);
	void setRectHeight(float height);
	void setRectWidth(float width);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, float speed = 0.005);
};

