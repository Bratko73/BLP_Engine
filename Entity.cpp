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

Entity::~Entity()
{
}

void Entity::setYvelocity(float velocityY)
{
	this->velocity.y = velocityY;
}

void Entity::setLife(bool life)
{
	this->life = life;
}

void Entity::setOnGround(bool val)
{
	onGround = val;
}

void Entity::setEntityHitboxTop(float personHitboxTop)
{
	this->entityHitbox.top = personHitboxTop;
}
void Entity::setEntityHitboxLeft(float personHitboxLeft)
{
	this->entityHitbox.left = personHitboxLeft;
}
