#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "GameMap.h"

class Entity
{
protected:
	sf::Vector2f velocity;
	sf::FloatRect entityHitbox;
	Animation animation;
	bool onGround;
	float gravitation;
	int life;
public:
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
	void draw(sf::RenderWindow& window);

	float& getXvelocity();
	float& getYvelocity();
	sf::FloatRect getEntityHitbox();

	void setYvelocity(float velocityY);
	void setLife(bool life);
	void setOnGround(bool val);
	void setEntityHitboxLeft(float personHitboxLeft);
	void setEntityHitboxTop(float personHitboxTop);
};