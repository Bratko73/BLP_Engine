#include "Person.h"
#include "Collision.h"
#include "GameMap.h"

Person::Person()
{
	//надо инициализировать animation
	offset.x = 0;
	offset.y = 0;
	//rect = sf::FloatRect(100, 180, 16, 16); //пока не знаем размеры(а надо бы)
	coordinates.x = 0.1;
	coordinates.y = 0.1;
}

Person::Person(std::string pathToFile)
{
	sf::Texture texture;
	texture.loadFromFile(pathToFile);
}

void Person::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		coordinates.x = -0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		coordinates.x = 0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (onGround) {
			coordinates.y = -0.27;
			onGround = false;
		}
}

void Person::update(float time, Person p)
{
	rect.left += coordinates.x * time;
	Collision::collision(0, p, Map);

	if (!onGround)
		coordinates.y = coordinates.y + 0.0005 * time;
	rect.top += coordinates.y * time;
	onGround = false;
	Collision::collision(0, p, Map);

	/*currentFrame += time * 0.005;
		if (currentFrame > 3)
			currentFrame -= 3;*/ 

	/*if (coordinates.x > 0)
			sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (coordinates.x < 0)
			sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));*/ // Тема Сани

	sprite.setPosition(rect.left - offset.x, rect.top - offset.y); 

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

float& Person::getRectLeft()
{
	return rect.left;
}
float& Person::getRectTop()
{
	return rect.top;
}
float& Person::getRectHeight()
{
	return rect.height;
}
float& Person::getRectWidth()
{
	return rect.width;
}
bool& Person::getOnGround() {
	return onGround;
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
