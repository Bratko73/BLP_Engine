#include "Person.h"
#include "Collision.h"
#include "GameMap.h"
#include "TestMap.h"

Person::Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect rectangle)
{
	this->heightOfJump = heightOfJump;
	this->gravitation = gravitation;
	this->speed = speed;
	coordinates.x = 0;
	coordinates.y = 0;
	this->rectangle = rectangle;
	animation.setPosition(coordinates);
	offset.x = 0;
	offset.y = 0;
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	life = true;
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
	rectangle.left += coordinates.x * time;
	Collision::collision(0, p, TileMap);

	if (!onGround)
		coordinates.y += gravitation * time;
	rectangle.top += coordinates.y * time;
	onGround = false;
	Collision::collision(1, p, TileMap);


	if (coordinates.x > 0)
			animation.update(time);
		if (coordinates.x < 0)
			animation.mirrorUpdate(time);

	animation.setPosition(rectangle.left - offset.x, rectangle.top - offset.y); 

	coordinates.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (rectangle.left > screenWidth / 2)
		offset.x = rectangle.left - screenWidth / 2;
}

void Person::Death(const int screenHeight)
{
	static float  pixelCounter = 0.1;
		if ((pixelCounter > 0) && (pixelCounter < heightOfJump * 237))
		{
			animation.setPosition(rectangle.left - offset.x, rectangle.top - pixelCounter);
			pixelCounter += 0.4;
		}
		else if (pixelCounter > heightOfJump * 237)
			pixelCounter = 0;
		else if ((rectangle.top - heightOfJump * 237 - pixelCounter) < screenHeight) {
			animation.setPosition(rectangle.left - offset.x, (rectangle.top - heightOfJump * 237 - pixelCounter));
			pixelCounter -=0.4;
		}
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

float Person::getRectangleLeft()
{
	return rectangle.left;
}

float Person::getRectangleTop()
{
	return rectangle.top;
}

float Person::getRectangleHeight()
{
	return rectangle.height;
}

float Person::getRectangleWidth()
{
	return rectangle.width;
}

sf::Sprite Person::getSprite()
{
	return animation.getSprite();
}

sf::FloatRect Person::getRectangle()
{
	return rectangle;
}

bool Person::getLife()
{
	return life;
}

void Person::setLife(bool life)
{
	this->life = life;
}

void Person::setOnGround(bool val)
{
	onGround = val;
}

void Person::setRectangleLeft(float left)
{
	rectangle.left = left;
}

void Person::setRectangleTop(float top)
{
	rectangle.top = top;
}

void Person::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	rectangle.height = size.y;
	rectangle.width = size.x;
}
