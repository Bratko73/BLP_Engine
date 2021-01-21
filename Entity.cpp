#include "Entity.h"

void Entity::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	entityHitbox.height = size.y;
	entityHitbox.width = size.x;
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(animation.getSprite());
}

float& Entity::getXvelocity()
{
	return velocity.x;
}

float& Entity::getYvelocity()
{
	return velocity.y;
}

sf::FloatRect Entity::getEntityHitbox()
{
	return entityHitbox;
}

int Entity::getLife()
{
	return life;
}

float Entity::getHeightOfJump()
{
	return heightOfJump;
}

Entity::~Entity()
{
}

void Entity::setVelocity(float velocityX, float velocityY)
{
	velocity.x = velocityX;
	velocity.y = velocityY;
}

void Entity::loseLife()
{
	life--;
}

void Entity::increaseLife()
{
	life++;
}

void Entity::setOnGround(bool val)
{
	onGround = val;
}

void Entity::setEntityHitboxTop(int personHitboxTop)
{
	this->entityHitbox.top = personHitboxTop;
}
void Entity::setEntityHitboxLeft(int personHitboxLeft)
{
	this->entityHitbox.left = personHitboxLeft;
}
