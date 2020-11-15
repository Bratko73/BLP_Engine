#include "Enemy.h"
#include "Collision.h"

Enemy::Enemy(std::string pathToFile, const float speed, const sf::FloatRect rect)
{
	this->speed = speed;
	this->rect = rect;
	coordinates.x = 0.05;
	currentFrame = 0;
	life = true;
	animation.setPosition(coordinates);
	animation.setSpriteSheet(pathToFile);
}

void Enemy::update(float time, Person& p)
{
	rect.left += coordinates.x * time;

	animation.update(time);
	if(!life)
		Enemy::setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(58, 0), 2, 0, 0.005);

	animation.setPosition(rect.left - p.getOffsetX(), rect.top - p.getOffsetY());
}

void Enemy::move(Enemy& n)
{
	if (Collision::npcCollision(n, TileMap))
		n.coordinates.x *= -1;
}

void Enemy::Death(Person& p)
{
	if (p.getRect().intersects(Enemy::rect))
	{
		if (life) {
			if (p.getY() > 0) {
				coordinates.x = 0;
				p.getY() = -0.2;
				life = false;
			}
		}
	}
}

void Enemy::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	rect.height = size.y;
	rect.width = size.x;
}

float& Enemy::getX()
{
	return coordinates.x;
}

sf::Sprite Enemy::getSprite()
{
	return animation.getSprite();
}

float Enemy::getRectLeft()
{
	return rect.left;
}
float Enemy::getRectTop()
{
	return rect.top;
}
float Enemy::getRectHeight()
{
	return rect.height;
}
float Enemy::getRectWidth()
{
	return rect.width;
}

void Enemy::setRectLeft(float left)
{
	rect.left = left;
}