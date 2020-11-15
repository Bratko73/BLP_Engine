#include "Person.h"
#include "Collision.h"
#include "GameMap.h"
#include "TestMap.h"

Person::Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect rect)
{
	this->heightOfJump = heightOfJump;
	this->gravitation = gravitation;
	this->speed = speed;
	coordinates.x = 0;
	coordinates.y = 0;
	this->rect = rect;
	animation.setPosition(coordinates);
	offset.x = 0;
	offset.y = 0;
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
}

void Person::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		coordinates.x = -speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		coordinates.x = speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (onGround) {
			coordinates.y = -heightOfJump;
			onGround = false;
		}
}

void Person::update(float time, Person& p)
{
	rect.left += coordinates.x * time;
	Collision::collision(0, p, TileMap);

	if (!onGround)
		coordinates.y = coordinates.y + gravitation * time;
	rect.top += coordinates.y * time;
	onGround = false;
	Collision::collision(1, p, TileMap);


	if (coordinates.x > 0)
			animation.update(time);
		if (coordinates.x < 0)
			animation.mirrorUpdate(time);

	animation.setPosition(rect.left - offset.x, rect.top - offset.y); 

	coordinates.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (rect.left > screenWidth / 2)
		offset.x = rect.left - screenWidth / 2;
}

float& Person::getX()
{
	return coordinates.x;
}

float& Person::getY()
{
	return coordinates.y;
}

float& Person::getOffsetX()
{
	return offset.x;
}

float& Person::getOffsetY()
{
	return offset.y;
}

float Person::getRectLeft()
{
	return rect.left;
}

float Person::getRectTop()
{
	return rect.top;
}

float Person::getRectHeight()
{
	return rect.height;
}

float Person::getRectWidth()
{
	return rect.width;
}

sf::Sprite Person::getSprite()
{
	return animation.getSprite();
}

void Person::setOnGround(bool val) 
{
	onGround = val;
}

void Person::setRectLeft(float left)
{
	rect.left = left;
}

void Person::setRectTop(float top)
{
	rect.top = top;
}

void Person::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	rect.height = size.y;
	rect.width = size.x;
}
