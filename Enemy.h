#pragma once
#include "Person.h"
#include "Animation.h"
#include "Interface.h"
#include "GameMap.h"

class Enemy {
protected:
	sf::Vector2f velocity;
	sf::FloatRect enemyHitbox;
	int life;
	Animation animation;
	bool onGround;
	float gravitation;
public:
	virtual void update(float time, Person& p) = 0;
	virtual void move(GameMap& map) = 0;
	virtual void Death(Person& p, Interface& i) = 0;
	virtual void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	float& getXvelocity();
	float& getYvelocity();
	void setYvelocity(float velocityY);
	std::string getName();
	sf::FloatRect getEnemyHitbox();
	void setEnemyHitboxLeft(float enemyHitboxLeft);
	void setEnemyHitboxTop(float enemyHitboxTop);
	void setOnGround(bool val);
	void setLife(int life);
};
