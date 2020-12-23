#pragma once
#include "Enemy.h"

class Turtle : public Enemy {
	float heightOfJump;
public:
	Turtle(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation, float heightOfJump);
	~Turtle();
	void update(float time, Person& p);
	void move(GameMap& map);
	void Death(Person& p, Interface& i);
	int getLife();
};