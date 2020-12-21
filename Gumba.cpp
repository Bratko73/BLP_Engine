#include "Gumba.h"
#include "Collision.h"


Gumba::Gumba(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation)
{
	this->gravitation = gravitation;
	this->entityHitbox = enemyHitbox;
	velocity.x = speed;
	life = 1;
	animation.setPosition(velocity);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
}

void Gumba::update(float time, Person& p)
{
		entityHitbox.left += velocity.x * time;

		if (!onGround)
			velocity.y += gravitation * time;
		entityHitbox.top += velocity.y * time;
		onGround = false;

		if (velocity.x > 0)
			animation.update(time);
		if (velocity.x < 0)
			animation.mirrorUpdate(time);
		static int timeToDisappear = 250;
		if (!life) {
			if (timeToDisappear > 0) {
				Gumba::setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(58, 0), 2, 0, 0);
				timeToDisappear--;
			}
			else if (timeToDisappear == 0) {
				animation.makeInvisible();
				timeToDisappear = 250;
			}
		}
		animation.setPosition(entityHitbox.left - p.getOffsetX(), entityHitbox.top - p.getOffsetY());
}

void Gumba::move(GameMap& map)
{
	Collision::collision(1, *this, map);
	if (Collision::collision(0, *this, map))
		velocity.x *= -1;
}

void Gumba::Death(Person& p, Interface& i)
{
	const float MarioYvelocityAfterKill = -0.2;
	const int numberOfPointsPerKill = 10;
	if (p.getEntityHitbox().intersects(Enemy::entityHitbox))
		if (life)
			if (p.getYvelocity() > 0) {
				p.setYvelocity(MarioYvelocityAfterKill);
				i.increaceScore(numberOfPointsPerKill);
				life--;
				velocity.x = 0;
			}
			else
			{
				p.setLife(false);
			}
}
