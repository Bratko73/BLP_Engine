#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Entity.h"

class Person : public Entity
{
private:
	float speed;
	sf::Vector2f offset;
	float heightOfJump;
	sf::Texture jumpTexture;
	sf::Sprite jumpSprite;
public:
	Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect personHitbox);

	void move();
	void update(float time, GameMap& map);
	void isEdgeOfMap(const int screenWidth);
	bool Death(const int screenHeight);

	float& getOffsetX();
	float& getOffsetY();
	bool getLife();
	bool isOnGround();
	void clearOffSet();
	void createJump(std::string pathToFile);
};

