#include "Enemy.h"
#include "Collision.h"


Enemy::Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle, float gravitation, const std::string name, float heightOfJump)
{
	this->gravitation = gravitation;
	this->rectangle = rectangle;
	coordinates.x = speed;
	life = true;
	animation.setPosition(coordinates);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	this->name = name;
	this->heightOfJump = heightOfJump;
}

void Enemy::update(float time, Person& p)
{
	rectangle.left += coordinates.x * time;

	if (!onGround)
		coordinates.y += gravitation * time;
	rectangle.top += coordinates.y * time;
	onGround = false;

	if (coordinates.x > 0)
		animation.update(time);
	if (coordinates.x < 0)
		animation.mirrorUpdate(time);
	if(!life)
		if (name == "Lenin")
			Enemy::setAnimationSettings(sf::Vector2i(16,16), sf::Vector2i(58, 0), 2, 0, 0);
		else if (name == "Turtle")
			Enemy::setAnimationSettings(sf::Vector2i(16,13), sf::Vector2i(388, 268), 2, 0, 0);

	animation.setPosition(rectangle.left - p.getOffsetX(), rectangle.top - p.getOffsetY());
}

void Enemy::move(Enemy& n)
{
	Collision::npcCollision(1, n, TileMap);
	if (Collision::npcCollision(0, n, TileMap))
			n.coordinates.x *= -1;
	if (name == "Turtle") {
		if (coordinates.x > 0) {
			if (TileMap[int(rectangle.top) / 16 + 1][int(rectangle.left) / 16 + 2] == '0' || TileMap[int(rectangle.top) / 16 + 1][int(rectangle.left) / 16 + 2] == 'r')
				if (onGround) {
					coordinates.y = -heightOfJump;
					onGround = false;
				}
		}
		else if (coordinates.x < 0)
			if (rectangle.left > 33)
				if (TileMap[int(rectangle.top) / 16 + 1][int(rectangle.left) / 16 - 2] == '0' || TileMap[int(rectangle.top) / 16 + 1][int(rectangle.left) / 16 - 2] == 'r')
					if (onGround) {
						coordinates.y = -heightOfJump;
						onGround = false;
					}
	}
}

bool Enemy::Death(Person& p, Interface& i)
{
	if (p.getRectangle().intersects(Enemy::rectangle))
	{
		if (life) {
			if (p.getY() > 0) {
				coordinates.x = 0;
				p.getY() = -0.1;
				if (name == "Lenin")
					i.increaceScore(10);
				else if (name == "Turtle")
					i.increaceScore(25);
				life = false;
				return true;
			}
			else {
				p.setLife(false);
			}
		}
	}
	return false;
}

void Enemy::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	rectangle.height = size.y;
	rectangle.width = size.x;
}

void Enemy::play(float time, Person& Player, Interface& interface, Enemy enemy[], const int index)
{
		enemy[index].move(enemy[index]);
		enemy[index].update(time, Player);
		enemy[index].Death(Player, interface);
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

std::string Enemy::getName()
{
	return name;
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
