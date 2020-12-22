#pragma once
#include "Enemy.h"

class Gumba : public Enemy {
public:
	Gumba(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation);
	~Gumba();
	void update(float time, Person& p);
	void move(GameMap& map);
	void Death(Person& p, Interface& i);
};
