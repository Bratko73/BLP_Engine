#include "Enemy.h"
#include "Collision.h"


Enemy::Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle, float gravitation)
{
	this->gravitation = gravitation;
	this->rectangle = rectangle;
	coordinates.x = speed;
	life = true;
	animation.setPosition(coordinates);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
}

void Enemy::update(float time, Person& p)
{
	rectangle.left += coordinates.x * time;

	if (!onGround)
		coordinates.y += gravitation * time;
	rectangle.top += coordinates.y * time;
	onGround = false;

	animation.update(time);
	if(!life)
		Enemy::setAnimationSettings(sf::Vector2i(17, 16), sf::Vector2i(58, 0), 2, 0, 0.005);

	animation.setPosition(rectangle.left - p.getOffsetX(), rectangle.top - p.getOffsetY());
}

void Enemy::move(Enemy& n)
{
	Collision::npcCollision(1, n, TileMap);
	if (Collision::npcCollision(0, n, TileMap))
		n.coordinates.x *= -1;
}

void Enemy::Death(Person& p)
{
	if (p.getRectangle().intersects(Enemy::rectangle))
	{
		if (life) {
			if (p.getY() > 0) {
				coordinates.x = 0;
				p.getY() = -0.1;
				life = false;
			}
			else {
				p.Death();
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

float& Enemy::getY()
{
	return coordinates.y;
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

void Enemy::setRectangleTop(float top)
{
	rectangle.top = top;
}

void Enemy::setOnGround(bool val)
{
	this->onGround = val;
}
