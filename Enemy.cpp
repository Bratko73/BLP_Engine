#include "Enemy.h"
#include "Collision.h"


Enemy::Enemy(std::string pathToFile, const float speed, const sf::FloatRect rectangle, float gravitation, const std::string name, float heightOfJump)
{
	this->gravitation = gravitation;
	this->rectangle = rectangle;
	coordinates.x = speed;
	if (name == "Lenin")
		life = 1;
	else if (name == "Turtle")
		life = 3;
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
	static int timeToDisappear = 250;
	if (life == 0 && name == "Lenin") {
		if (timeToDisappear > 0) {
			Enemy::setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(58, 0), 2, 0, 0);
			timeToDisappear--;
		}
		else if (timeToDisappear == 0){
			animation.makeInvisible();
			timeToDisappear = 250;
		}
	}
	if (name == "Turtle" && life == 2)
		Enemy::setAnimationSettings(sf::Vector2i(18, 14), sf::Vector2i(387, 267), 2, 0, 0);
	else if (name == "Turtle" && life == 1)
		Enemy::setAnimationSettings(sf::Vector2i(17, 14), sf::Vector2i(387, 267), 5, 0, 0.005);

	animation.setPosition(rectangle.left - p.getOffsetX(), rectangle.top - p.getOffsetY());
}

void Enemy::move(GameMap& map)
{
	Collision::npcCollision(1, *this, map);
	if (Collision::npcCollision(0, *this, map))
			coordinates.x *= -1;

	if (name == "Turtle" && life == 2) {
		if (coordinates.x > 0) {
			if (map.get_Hardness(int(rectangle.left) / 16 + 2, int(rectangle.top) / 16 + 1) == true)
				if (onGround) {
					coordinates.y = -heightOfJump;
					onGround = false;
				}
		}
		else if (coordinates.x < 0)
				if (map.get_Hardness(int(rectangle.left) / 16 - 2, int(rectangle.top) / 16 + 1) == true)
					if (onGround) {
						coordinates.y = -heightOfJump;
						onGround = false;
					}
	}
}

void Enemy::Death(Person& p, Interface& i)
{
	if (p.getRectangle().intersects(Enemy::rectangle))
	{
		if (life) {
			if (p.getY() > 0) {
				p.getY() = -0.2;
				if (name == "Lenin") {
					i.increaceScore(10);
					life--;
					coordinates.x = 0;
				}
				else if (name == "Turtle" && life == 3) {
					i.increaceScore(15);
					life--;
					coordinates.x = 0;
				}
				else if (name == "Turtle" && life == 2) {
					life--;
					coordinates.x += 0.15;
				}
				else if (name == "Turtle" && life == 1) {
					life++;
					coordinates.x = 0;
				}
			}
			else if(!(name == "Turtle" && life == 2))
			{
				p.setLife(false);
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

//void Enemy::play(float time, Person& Player, Interface& interface, Enemy enemy[], const int index)
//{
//		enemy[index].move();
//		enemy[index].update(time, Player);
//		enemy[index].Death(Player, interface);
//}

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

sf::FloatRect Enemy::getRectangle()
{
	return rectangle;
}
