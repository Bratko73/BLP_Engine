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
	sf::Texture jumpTexture;
	sf::Sprite jumpSprite;
public:
	Person();
	Person(const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect personHitbox);
	~Person();
	void move(int flag = 0);
	void update(float time);
	void isEdgeOfMap(const int screenWidth);
	bool death(const int screenHeight);
	void changeModel(const int parametr);
	bool getOnGround();
	float getGravitation();

	float& getOffsetX();
	float& getOffsetY();
	bool isOnGround();
	void clearOffSet();
	void createJump(std::string pathToFile);
	void setEntityHitboxLeft(float hitboxLeft);
	void setEntityHitboxTop(float hitboxTop);
};

