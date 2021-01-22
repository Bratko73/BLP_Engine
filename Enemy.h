#pragma once
#include "Person.h"
#include "Animation.h"
#include "Interface.h"
#include "GameMap.h"

class Enemy : public Entity{
public:
	virtual void update(float time, Person& p) = 0;
	virtual void move(GameMap& map) = 0;
	virtual ~Enemy();
};
