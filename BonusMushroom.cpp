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
	heightOfJump = 0;
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

BonusMushroom::~BonusMushroom()
{
}

void BonusMushroom::setMushroomHitboxWidth(float hitBoxWidth)
{
	entityHitbox.width = hitBoxWidth;
}

float BonusMushroom::getSpeed()
{
	return speed;
}
