#include "Person.h"
#include "Collision.h"

Person::Person(std::string pathToFile, const float speed, const float gravitation, const float heightOfJump, const sf::FloatRect personHitbox)
{
	this->heightOfJump = heightOfJump;
	this->gravitation = gravitation;
	this->speed = speed;
	velocity.x = 0;
	velocity.y = 0;
	this->personHitbox = personHitbox;
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
	personHitbox.left += velocity.x * time;
	Collision::collision(0, *this, map);

	if (!onGround)
		velocity.y += gravitation * time;
	personHitbox.top += velocity.y * time;
	onGround = false;
	Collision::collision(1, *this, map);


	if (velocity.x > 0)
			this->animation.update(time);
		if (velocity.x < 0)
			this->animation.mirrorUpdate(time);

	animation.setPosition(personHitbox.left - offset.x, personHitbox.top - offset.y); 

	velocity.x = 0;
}

void Person::isEdgeOfMap(const int screenWidth)
{
	if (personHitbox.left > screenWidth / 2)          //так как персонаж находится в центре экрана, ширину экрана делю пополам
		offset.x = personHitbox.left - screenWidth / 2;
}

bool Person::Death(const int screenHeight)
{
	life = false;
	const float speedOfDeath = 0.4; //скорость, с которой спрайт персонажа "уходит" под карту
	const int jumpCoeff = 237;      //с помощью этого параметра поднимаю спрайт персонажа примерно на высоту его прыжка, чтобы было ка кв оригинал марио
	static float  pixelCounter = 0.1;
	if ((pixelCounter > 0) && (pixelCounter < heightOfJump * jumpCoeff))
	{
		animation.setPosition(personHitbox.left - offset.x, personHitbox.top - pixelCounter);
		pixelCounter += speedOfDeath;
		return 0;
	}
	else if (pixelCounter > heightOfJump* jumpCoeff) {
		pixelCounter = 0;
		return 0;
	}
	else if ((personHitbox.top - heightOfJump * jumpCoeff - pixelCounter) < screenHeight) {
		animation.setPosition(personHitbox.left - offset.x, (personHitbox.top - heightOfJump * jumpCoeff - pixelCounter));
		pixelCounter -= speedOfDeath;
		return 0;
	}
	else {
		pixelCounter = 0.1;
		return 1;
	}
}

void Person::draw(sf::RenderWindow& window)
{
	window.draw(animation.getSprite());
}

float& Person::getXvelocity()
{
	return velocity.x;
}

float& Person::getYvelocity()
{
	return velocity.y;
}

float& Person::getOffsetX()
{
	return offset.x;
}

float& Person::getOffsetY()
{
	return offset.y;
}

sf::FloatRect Person::getPersonHitbox()
{
	return personHitbox;
}

bool Person::getLife()
{
	return life;
}

bool Person::isOnGround()
{
	return onGround;
}

void Person::setYvelocity(float velocityY)
{
	this->velocity.y = velocityY;
}

void Person::clearOffSet()
{
	offset.x = 0;
	offset.y = 0;
}

void Person::setLife(bool life)
{
	this->life = life;
}

void Person::setOnGround(bool val)
{
	onGround = val;
}

void Person::setPersonHitboxTop(float personHitboxTop)
{
	this->personHitbox.top = personHitboxTop;
}
void Person::setPersonHitboxLeft(float personHitboxLeft)
{
	this->personHitbox.left = personHitboxLeft;
}

void Person::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	personHitbox.height = size.y;
	personHitbox.width = size.x;
}
