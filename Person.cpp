#include "Person.h"
#include "Collision.h"

Person::Person()
{
	this->heightOfJump = 0;
	this->gravitation = 0;
	this->speed = 0;
	velocity.x = 0;
	velocity.y = 0;
	this->entityHitbox = sf::FloatRect();
	offset.x = 0;
	offset.y = 0;
	onGround = 0;
	life = 0;
}

Person::Person( const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect personHitbox)
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
	onGround = 0;
	life = 1;
}

Person::~Person()
{}

void Person::move(int flag)
{
	if (flag == 1)
		velocity.x = -speed;

	if (flag == -1)
		velocity.x = speed;

	if (flag == 2)
		if (onGround) {
			velocity.y = -heightOfJump;
			onGround = false;
		}
}

void Person::update(float time)
{
	if (velocity.x > 0)
		this->animation.update(time);
	if (velocity.x < 0)
		this->animation.mirrorUpdate(time);
	if (velocity.x == 0)
		this->animation.startOver();
	animation.setPosition(entityHitbox.left - offset.x, entityHitbox.top - offset.y);
	jumpSprite.setPosition(entityHitbox.left - offset.x, entityHitbox.top - offset.y);
	velocity.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (entityHitbox.left > screenWidth / 2)          //��� ��� �������� ��������� � ������ ������, ������ ������ ���� �������
		offset.x = entityHitbox.left - screenWidth / 2;
}

bool Person::death(const int screenHeight)
{
	const float speedOfDeath = 2; //��������, � ������� ������ ��������� "������" ��� �����
	const int jumpCoeff = 237;      //� ������� ����� ��������� �������� ������ ��������� �������� �� ������ ��� ������, ����� ���� �� �� �������� �����
	static float  pixelCounter = 0.1; //��� �������� "�����" ����� ��� �����
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

void Person::changeModel(const int parametr)
{
	life = parametr;
	if (life == 1) {
		animation.setSpriteSheet("sourses/sprites/Mario_tileset.png");
		setAnimationSettings(sf::Vector2i(16, 16), sf::Vector2i(80, 144), 4, 15, 0.005);
	}
	else if (life == 2) {
		animation.setSpriteSheet("sourses/sprites/Turtle.png");
		setAnimationSettings(sf::Vector2i(15, 32), sf::Vector2i(293, 264), 4, 15, 0.005);
	}
}

bool Person::getOnGround()
{
	return onGround;
}

float Person::getGravitation()
{
	return gravitation;
}

float& Person::getOffsetX()
{
	return offset.x;
}

float& Person::getOffsetY()
{
	return offset.y;
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

void Person::createJump(std::string pathToFile)
{
	jumpTexture.loadFromFile(pathToFile);
	jumpSprite.setTexture(jumpTexture);
	jumpSprite.setTextureRect(sf::IntRect(231,144,16,16));
}

void Person::setEntityHitboxLeft(float hitboxLeft)
{
	entityHitbox.left = hitboxLeft;
}

void Person::setEntityHitboxTop(float hitboxTop)
{
	entityHitbox.top = hitboxTop;
}
