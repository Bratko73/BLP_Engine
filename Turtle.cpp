#include "Turtle.h"
#include "Collision.h"

Turtle::Turtle(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation, float heightOfJump)
{
	this->gravitation = gravitation;
	this->entityHitbox = enemyHitbox;
	velocity.x = speed;
	life = 3;
	animation.setPosition(velocity);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	this->heightOfJump = heightOfJump;
}

void Turtle::update(float time, Person& p)
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

		if (life == 2)
			Turtle::setAnimationSettings(sf::Vector2i(18, 14), sf::Vector2i(387, 267), 2, 0, 0);
		else if (life == 1)
			Turtle::setAnimationSettings(sf::Vector2i(17, 14), sf::Vector2i(387, 267), 5, 0, 0.005);
		else if (life == 0)
			animation.makeInvisible();

		animation.setPosition(entityHitbox.left - p.getOffsetX(), entityHitbox.top - p.getOffsetY());
}

void Turtle::move(GameMap& map)
{
	const int pixelsInTile = 16;
	const int visibilityOfTurtle = 2;
	Collision::collision(1, *this, map);
	if (Collision::collision(0, *this, map))
		velocity.x *= -1;
	if (life == 3) {
		if (velocity.x > 0) {
			if (map.get_Hardness(int(entityHitbox.left) / pixelsInTile + visibilityOfTurtle, int(entityHitbox.top) / pixelsInTile + 1) == true)
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
		}
		else if (velocity.x < 0)
			if (map.get_Hardness(int(entityHitbox.left) / pixelsInTile - visibilityOfTurtle, int(entityHitbox.top) / pixelsInTile + 1) == true)
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
	}
}

void Turtle::Death(Person& p, Interface& i)
{
	const float MarioYvelocityAfterKill = -0.2;
	const int numberOfPointsPerKill = 15;
	const float shellSpeed = 0.15;
	if (p.getEntityHitbox().intersects(Enemy::entityHitbox))
		if (life)
			if (p.getYvelocity() > 0) {
				p.setYvelocity(MarioYvelocityAfterKill);
				if (life == 3) {
					i.increaceScore(numberOfPointsPerKill);
					life--;
					velocity.x = 0;
				}
				else if (life == 2) {
					life--;
					velocity.x += shellSpeed;
				}
				else if (life == 1) {
					life++;
					velocity.x = 0;
				}
			}
			else
			{
				static int immortalTime = 10;
				if (p.getLife() == 2) {
					p.changeLife(1);
					immortalTime = 10;
				}
				else
					if (immortalTime < 0)
						p.setLife(0);
				immortalTime--;
			}
}