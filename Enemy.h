#pragma once
#include "Person.h"
#include "Animation.h"

class Enemy {
	sf::Vector2f coordinates;
	sf::FloatRect rectangle;
	bool life;
	float currentFrame;
	float speed;
	Animation animation;
	bool onGround;
	float gravitation;
public:
	Enemy();
	Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle, float gravitation);
	void update(float time, Person& p);
	void move(Enemy& n);
	void Death(Person& p);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);

	float& getX();
	float& getY();
	sf::Sprite getSprite();
	float getRectangleLeft();
	float getRectangleTop();
	float getRectangleHeight();
	float getRectangleWidth();

	void setRectangleLeft(float left);
	void setRectangleTop(float top);
	void setOnGround(bool val);
};
