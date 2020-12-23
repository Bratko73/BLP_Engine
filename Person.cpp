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

Person::~Person()
{}

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

void Person::update(float time, GameMap& map, Interface& i)
{
	entityHitbox.left += velocity.x * time;
	Collision::collision(0, *this, map);

	if (!onGround)
		velocity.y += gravitation * time;
	entityHitbox.top += velocity.y * time;
	onGround = false;
	if (Collision::collision(1, *this, map) == 3)
		i.increaceMoney(1);


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
	if (entityHitbox.left > screenWidth / 2)          //так как персонаж находитс€ в центре экрана, ширину экрана делю пополам
		offset.x = entityHitbox.left - screenWidth / 2;
}

bool Person::death(const int screenHeight)
{
	const float speedOfDeath = 2; //скорость, с которой спрайт персонажа "уходит" под карту
	const int jumpCoeff = 237;      //с помощью этого параметра поднимаю спрайт персонажа примерно на высоту его прыжка, чтобы было ка кв оригинал марио
	static float  pixelCounter = 0.1; //дл€ плавного "ухода" ћарио под землю
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

void Person::changeLife(const int parametr)
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

float& Person::getOffsetX()
{
	return offset.x;
}

float& Person::getOffsetY()
{
	return offset.y;
}

int Person::getLife()
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

void Person::createJump(std::string pathToFile)
{
	jumpTexture.loadFromFile(pathToFile);
	jumpSprite.setTexture(jumpTexture);
	jumpSprite.setTextureRect(sf::IntRect(231,144,16,16));
}


