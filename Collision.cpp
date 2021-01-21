#include "Collision.h"

bool Collision::collision(sf::IntRect first, sf::IntRect second)
{
	if (first.intersects(second))
		return true;
	else
		return false;
}

Collision::~Collision()
{}
