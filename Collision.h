#pragma once
#include "Person.h"
#include "Enemy.h"
#include "GameMap.h"

class Collision {
public:
	static bool collision(sf::IntRect first, sf::IntRect second);
	~Collision();
};