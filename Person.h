#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "GameMap.h"

class Person
{
private:
	float speed;
	sf::Vector2f offset;
	sf::Vector2f velocity;
	sf::FloatRect personHitbox;
	Animation animation;
	bool onGround;
	float gravitation;
	float heightOfJump;
	bool life;
public:
	Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect Rectangle);

	void move();
	void update(float time, GameMap& map);
	void isEdgeOfMap(const int screenWidth);
	bool Death(const int screenHeight);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
	void draw(sf::RenderWindow& window);

	float& getXvelocity();
	float& getYvelocity();
	float& getOffsetX();
	float& getOffsetY();
	sf::FloatRect getPersonHitbox();
	bool getLife();
	bool isOnGround();
	void setYvelocity(float velocityY);
	void clearOffSet();
	void setLife(bool life);
	void setOnGround(bool val);
	void setPersonHitboxLeft(float personHitboxLeft);
	void setPersonHitboxTop(float personHitboxTop);
};

