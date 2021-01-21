#include "Turtle.h"
#include "Collision.h"

Turtle::Turtle(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation, float heightOfJump)
{
	this->gravitation = gravitation;
	this->entityHitbox = enemyHitbox;
	velocity.x = speed;
	life = 11;
	animation.setPosition(velocity);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	this->heightOfJump = heightOfJump;
}

Turtle::~Turtle()
{
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
	if (life == 11) {
		if (velocity.x > 0) {
			if (map.get_Hardness(int(entityHitbox.left) / pixelsInTile + visibilityOfTurtle, int(entityHitbox.top) / pixelsInTile + 1) == true)//высота черепахи 1.5 тайла, +1, чтобы она находила препятствие 
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
		}
		else if (velocity.x < 0)
			if (map.get_Hardness(int(entityHitbox.left) / pixelsInTile - visibilityOfTurtle, int(entityHitbox.top) / pixelsInTile + 1) == true)//высота черепахи 1.5 тайла, +1, чтобы она находила препятствие
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
	}
}

