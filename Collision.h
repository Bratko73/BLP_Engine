#pragma once
#include "Person.h"
#include "Enemy.h"
#include "GameMap.h"

class Collision {
public:
	static bool collision(sf::FloatRect first, sf::FloatRect second);
	~Collision();
};