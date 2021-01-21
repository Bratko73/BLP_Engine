#include "Gumba.h"
#include "Collision.h"


Gumba::Gumba(const float speed, const sf::FloatRect enemyHitbox, float gravitation)
{
	this->gravitation = gravitation;
	this->entityHitbox = enemyHitbox;
	velocity.x = speed;
	life = 1;
	animation.setPosition(velocity);
	onGround = 0;
	heightOfJump = 0;
}

Gumba::~Gumba()
{}

void Gumba::update(float time, Person& p)
{
	const int screenWidth = 400;
	if (entityHitbox.left - p.getOffsetX() <= screenWidth) {
		if (life == 1) {
			entityHitbox.left += velocity.x * time;

			if (!onGround)
				velocity.y += gravitation * time;
			entityHitbox.top += velocity.y * time;
			onGround = false;

			if (velocity.x > 0)
				animation.update(time);
			if (velocity.x < 0)
				animation.mirrorUpdate(time);
		}
		static int timeToDisappear = 250;
		if (life == 0) {
			if (timeToDisappear > 0) {
				Gumba::setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(58, 0), 2, 0, 0);
				timeToDisappear--;
			}
			else if (timeToDisappear == 0) {
				animation.makeInvisible();
				timeToDisappear = 250;
			}
		}
	}
	animation.setPosition(entityHitbox.left - p.getOffsetX(), entityHitbox.top - p.getOffsetY());
}

void Gumba::move(GameMap& map)
{
}

