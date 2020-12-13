#pragma once
#include "Person.h"
#include "TestMap.h"
#include "Enemy.h"
#include "GameMap.h"

class Collision {
public:
	static void collision(bool flag, Person& p, GameMap& map);
	static bool npcCollision(bool flag, Enemy& n, GameMap& map);
};