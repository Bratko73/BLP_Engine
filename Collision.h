#pragma once
#include "Person.h"
#include "TestMap.h"
#include "Enemy.h"

class Collision {
public:
	static void collision(bool flag, Person& p, sf::String Map[]);
	static bool npcCollision(bool flag, Enemy& n, sf::String Map[]);
};