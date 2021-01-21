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
	float heightOfJump;
public:
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
	void draw(sf::RenderWindow& window);

	float& getXvelocity();
	float& getYvelocity();
	sf::FloatRect getEntityHitbox();
	int getLife();
	float getHeightOfJump();
	~Entity();
	void setVelocity(float velocityX, float velocityY);
	void loseLife();
	void increaseLife();
	void setOnGround(bool val);
	void setEntityHitboxLeft(int personHitboxLeft);
	void setEntityHitboxTop(int personHitboxTop);
	void setSpriteSheet(std::string pathToFile);
};