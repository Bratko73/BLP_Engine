#pragma once
#include "Entity.h"
#include "Person.h"
#include "Animation.h"
#include "Interface.h"
#include "GameMap.h"

class BonusMushroom : public Entity {
	float speed;
public:
	BonusMushroom(std::string pathToFile, const float gravitation, const sf::FloatRect personHitbox, float speed);
	void update(float time, Person& p);
	void move(GameMap& map);
	void Death(Person& p, Interface& i);
	~BonusMushroom();
};