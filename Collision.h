#pragma once
#include "Person.h"
#include "Enemy.h"
#include "GameMap.h"

class Collision {
public:
	static bool collision(bool flag, Entity& e, GameMap& map);
};