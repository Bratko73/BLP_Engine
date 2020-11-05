#include "Person.h"
#include "Collision.h"
#include "GameMap.h"
#include "TestMap.h"

Person::Person()
{
}

Person::Person(std::string pathToFile, float speed, float gravitation, float heightOfJump)
{
	this->heightOfJump = heightOfJump;
	this->gravitation = gravitation;
	this->speed = speed;
	coordinates.x = 0.1;
	coordinates.y = 0.1;
	rect = sf::FloatRect(100, 180, 16, 16);
	animation.setPosition(coordinates);
	offset.x = 0;
	offset.y = 0;
	animation.setSpriteSheet(pathToFile);
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

void Person::setOffsetX(float x)
{
	offset.x = x;
}

void Person::setOffsetY(float y)
{
	offset.y = y;
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
bool Person::getOnGround() {
	return onGround;
}
sf::Sprite Person::getSprite()
{
	return animation.getSprite();
}
void Person::setOnGround(bool val) {
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
void Person::setRectHeight(float height)
{
	rect.height = height;
}
void Person::setRectWidth(float width)
{
	rect.width = width;
}

void Person::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, speed);
	rect.height = size.y;
	rect.width = size.x;
}
