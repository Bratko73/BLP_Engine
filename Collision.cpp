#include "Collision.h"

bool Collision::collision(sf::FloatRect first, sf::FloatRect second)
{
	if (first.intersects(second))
		return true;
	else
		return false;
}

Collision::~Collision()
{}
