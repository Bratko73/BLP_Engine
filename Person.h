#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include "Entity.h"
#include "Interface.h"

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
	~Person();
	void move();
	void update(float time, GameMap& map, Interface& i);
	void isEdgeOfMap(const int screenWidth);
	bool death(const int screenHeight);
	void changeLife(const int parametr);

	float& getOffsetX();
	float& getOffsetY();
	int getLife();
	bool isOnGround();
	void clearOffSet();
	void createJump(std::string pathToFile);
};

