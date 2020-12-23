#include "BonusMushroom.h"
#include "Collision.h"


BonusMushroom::BonusMushroom(std::string pathToFile, const float gravitation, const sf::FloatRect enemyHitbox, float speed)
{
	this->speed = speed;
	this->gravitation = gravitation;
	velocity.x = 0;
	velocity.y = 0;
	this->entityHitbox = enemyHitbox;
	animation.setPosition(velocity);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	life = 2;
}

void BonusMushroom::update(float time, Person& p)
{
	if (life != 2) {
		entityHitbox.left += velocity.x * time;
		if (!onGround)
			velocity.y += gravitation * time;
		entityHitbox.top += velocity.y * time;
		onGround = false;

		if (life == 0)
			animation.makeInvisible();
		else
			setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(0, 0), 3, 0, 0);

		animation.setPosition(entityHitbox.left - p.getOffsetX(), entityHitbox.top - p.getOffsetY());
	}
}

void BonusMushroom::move(GameMap& map)
{
	if (life == 1) {
		Collision::collision(1, *this, map);
		if (Collision::collision(0, *this, map))
			velocity.x *= -1;
	}
}

void BonusMushroom::activate(Person& p, Interface& i)
{
	const int numberOfPointsPerKill = 100;
	const int tileSize = 16;
	if (p.getEntityHitbox().intersects(Entity::entityHitbox))
		if (life == 2) {
			entityHitbox.top -= tileSize;
			velocity.x = -speed;
			life--;
		}
		else if (life == 1) {
			i.increaceScore(numberOfPointsPerKill);
			life--;
			velocity.x = 0;
			p.changeLife(2);
		}
}

BonusMushroom::~BonusMushroom()
{
}
