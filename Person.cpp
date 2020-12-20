#include "Person.h"
#include "Collision.h"

Person::Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect personHitbox)
{
	this->heightOfJump = heightOfJump;
	this->gravitation = gravitation;
	this->speed = speed;
	velocity.x = 0;
	velocity.y = 0;
	this->entityHitbox = personHitbox;
	animation.setPosition(velocity);
	offset.x = 0;
	offset.y = 0;
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	life = true;
}

void Person::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x = -speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x = speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (onGround) {
			velocity.y = -heightOfJump;
			onGround = false;
		}
}

void Person::update(float time, GameMap& map)
{
	entityHitbox.left += velocity.x * time;
	Collision::collision(0, *this, map);

	if (!onGround)
		velocity.y += gravitation * time;
	entityHitbox.top += velocity.y * time;
	onGround = false;
	Collision::collision(1, *this, map);


	if (velocity.x > 0)
			this->animation.update(time);
		if (velocity.x < 0)
			this->animation.mirrorUpdate(time);

	animation.setPosition(entityHitbox.left - offset.x, entityHitbox.top - offset.y);

	velocity.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (entityHitbox.left > screenWidth / 2)          //��� ��� �������� ��������� � ������ ������, ������ ������ ���� �������
		offset.x = entityHitbox.left - screenWidth / 2;
}

bool Person::Death(const int screenHeight)
{
	life = false;
	const float speedOfDeath = 0.4; //��������, � ������� ������ ��������� "������" ��� �����
	const int jumpCoeff = 237;      //� ������� ����� ��������� �������� ������ ��������� �������� �� ������ ��� ������, ����� ���� �� �� �������� �����
	static float  pixelCounter = 0.1;
	if ((pixelCounter > 0) && (pixelCounter < heightOfJump * jumpCoeff))
	{
		animation.setPosition(entityHitbox.left - offset.x, entityHitbox.top - pixelCounter);
		pixelCounter += speedOfDeath;
		return 0;
	}
	else if (pixelCounter > heightOfJump* jumpCoeff) {
		pixelCounter = 0;
		return 0;
	}
	else if ((entityHitbox.top - heightOfJump * jumpCoeff - pixelCounter) < screenHeight) {
		animation.setPosition(entityHitbox.left - offset.x, (entityHitbox.top - heightOfJump * jumpCoeff - pixelCounter));
		pixelCounter -= speedOfDeath;
		return 0;
	}
	else {
		pixelCounter = 0.1;
		return 1;
	}
}

float& Person::getOffsetX()
{
	return offset.x;
}

float& Person::getOffsetY()
{
	return offset.y;
}

bool Person::getLife()
{
	return life;
}

bool Person::isOnGround()
{
	return onGround;
}

void Person::clearOffSet()
{
	offset.x = 0;
	offset.y = 0;
}
