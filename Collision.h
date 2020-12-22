#pragma once
#include "Person.h"
#include "Enemy.h"
#include "GameMap.h"

class Collision {
public:
	static int collision(bool flag, Entity& e, GameMap& map);
};