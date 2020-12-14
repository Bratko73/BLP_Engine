#include "Person.h"
#include "Collision.h"

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

void Person::update(float time, GameMap& map)
{
	rectangle.left += coordinates.x * time;
	Collision::collision(0, *this, map);

	if (!onGround)
		coordinates.y += gravitation * time;
	rectangle.top += coordinates.y * time;
	onGround = false;
	Collision::collision(1, *this, map);


	if (coordinates.x > 0)
			this->animation.update(time);
		if (coordinates.x < 0)
			this->animation.mirrorUpdate(time);

	animation.setPosition(rectangle.left - offset.x, rectangle.top - offset.y); 

	coordinates.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (rectangle.left > screenWidth / 2)          //так как персонаж находится в центре экрана, ширину экрана делю пополам
		offset.x = rectangle.left - screenWidth / 2;
}

void Person::Death(const int screenHeight)
{
	const float speedOfDeath = 0.4; //скорость, с которой спрайт персонажа "уходит" под карту
	const int jumpCoeff = 237;      //с помощью этого параметра поднимаю спрайт персонажа примерно на высоту его прыжка, чтобы было ка кв оригинал марио
	static float  pixelCounter = 0.1;
		if ((pixelCounter > 0) && (pixelCounter < heightOfJump * jumpCoeff))
		{
			animation.setPosition(rectangle.left - offset.x, rectangle.top - pixelCounter);
			pixelCounter += speedOfDeath;
		}
		else if (pixelCounter > heightOfJump * jumpCoeff)
			pixelCounter = 0;
		else if ((rectangle.top - heightOfJump * jumpCoeff - pixelCounter) < screenHeight) {
			animation.setPosition(rectangle.left - offset.x, (rectangle.top - heightOfJump * jumpCoeff - pixelCounter));
			pixelCounter -= speedOfDeath;
		}
}

//void Person::play(float time, const int screenWidth, const int screenHeight, GameMap& map)
//{
//	if (life == true) {
//		move();
//		update(time, map);
//		isEdgeOfMap(screenWidth);
//	}
//	else
//		Death(screenHeight);
//}

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

bool Person::isOnGround()
{
	return onGround;
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
