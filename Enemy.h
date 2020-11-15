#pragma once
#include "Person.h"
#include "Animation.h"

class Enemy {
	sf::Vector2f coordinates;
	sf::FloatRect rect;
	bool life;
	float currentFrame;
	float speed;
	Animation animation;
public:
	Enemy(std::string pathToFile, const float speed, const sf::FloatRect rect);
	void update(float time, Person& p);
	void move(Enemy& n);
	void Death(Person& p);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);

	float& getX();
	sf::Sprite getSprite();
	float getRectLeft();
	float getRectTop();
	float getRectHeight();
	float getRectWidth();

	void setRectLeft(float left);
};
