#pragma once
#include "Enemy.h"
#include "Turtle.h"

class Gumba : public Enemy {
public:
	Gumba(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation);
	~Gumba();
	void update(float time, Person& p) override;
	void move(GameMap& map) override;
};
