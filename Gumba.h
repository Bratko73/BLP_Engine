#pragma once
#include "Enemy.h"

class Gumba : public Enemy {
public:
	Gumba(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation);
	void update(float time, Person& p);
	void move(GameMap& map);
	void Death(Person& p, Interface& i);
	void setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames = 0, int rangeBetweenFrames = 0, float speed = 0.005);
	void draw(sf::RenderWindow& window);
};