#include "Enemy.h"
#include "Collision.h"

Enemy::Enemy()
{
}

Enemy::Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle)
{
	this->speed = speed;
	this->rectangle = rectangle;
	coordinates.x = 0.05;
	currentFrame = 0;
	life = true;
	animation.setPosition(coordinates);
	animation.setSpriteSheet(pathToFile);
}

void Enemy::update(float time, Person& p)
{
	rectangle.left += coordinates.x * time;

	animation.update(time);
	if(!life)
		Enemy::setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(58, 0), 2, 0, 0.005);

	animation.setPosition(rectangle.left - p.getOffsetX(), rectangle.top - p.getOffsetY());
}

void Enemy::move(Enemy& n)
{
	if (Collision::npcCollision(n, TileMap))
		n.coordinates.x *= -1;
}

void Enemy::Death(Person& p)
{
	if (p.getRectangle().intersects(Enemy::rectangle))
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
	rectangle.height = size.y;
	rectangle.width = size.x;
}

float& Enemy::getX()
{
	return coordinates.x;
}

sf::Sprite Enemy::getSprite()
{
	return animation.getSprite();
}

float Enemy::getRectangleLeft()
{
	return rectangle.left;
}
float Enemy::getRectangleTop()
{
	return rectangle.top;
}
float Enemy::getRectangleHeight()
{
	return rectangle.height;
}
float Enemy::getRectangleWidth()
{
	return rectangle.width;
}

void Enemy::setRectangleLeft(float left)
{
	rectangle.left = left;
}