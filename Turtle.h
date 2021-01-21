#pragma once
#include "Enemy.h"

class Turtle : public Enemy {
public:
	Turtle( const float speed, const sf::FloatRect enemyHitbox, float gravitation, float heightOfJump);
	~Turtle();
	void update(float time, Person& p);
	void move(GameMap& map);
};