#include "Turtle.h"
#include "Collision.h"


Turtle::Turtle(std::string pathToFile, const float speed, const sf::FloatRect enemyHitbox, float gravitation, float heightOfJump)
{
	this->gravitation = gravitation;
	this->enemyHitbox = enemyHitbox;
	velocity.x = speed;
	life = 3;
	animation.setPosition(velocity);
	animation.setSpriteSheet(pathToFile);
	onGround = 0;
	this->heightOfJump = heightOfJump;
}

void Turtle::update(float time, Person& p)
{
	enemyHitbox.left += velocity.x * time;

	if (!onGround)
		velocity.y += gravitation * time;
	enemyHitbox.top += velocity.y * time;
	onGround = false;

	if (velocity.x > 0)
		animation.update(time);
	if (velocity.x < 0)
		animation.mirrorUpdate(time);
	static int timeToDisappear = 250;
	if (life == 2)
		Turtle::setAnimationSettings(sf::Vector2i(18, 14), sf::Vector2i(387, 267), 2, 0, 0);
	else if (life == 1)
		Turtle::setAnimationSettings(sf::Vector2i(17, 14), sf::Vector2i(387, 267), 5, 0, 0.005);
	else if (life == 0)
		animation.makeInvisible();

	animation.setPosition(enemyHitbox.left - p.getOffsetX(), enemyHitbox.top - p.getOffsetY());
}

void Turtle::move(GameMap& map)
{
	const int pixelsInTile = 16;
	const int visibilityOfTurtle = 2;
	Collision::npcCollision(1, *this, map);
	if (Collision::npcCollision(0, *this, map))
		velocity.x *= -1;
	if (life == 3) {
		if (velocity.x > 0) {
			if (map.get_Hardness(int(enemyHitbox.left) / pixelsInTile + visibilityOfTurtle, int(enemyHitbox.top) / pixelsInTile + 1) == true)
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
		}
		else if (velocity.x < 0)
			if (map.get_Hardness(int(enemyHitbox.left) / pixelsInTile - visibilityOfTurtle, int(enemyHitbox.top) / pixelsInTile + 1) == true)
				if (onGround) {
					velocity.y = -heightOfJump;
					onGround = false;
				}
	}
}

void Turtle::Death(Person& p, Interface& i)
{
	const float MarioYvelocityAfterKill = -0.2;
	const int numberOfPointsPerKill = 15;
	const float shellSpeed = 0.15;
	if (p.getPersonHitbox().intersects(Enemy::enemyHitbox))
		if (life)
			if (p.getYvelocity() > 0) {
				p.setYvelocity(MarioYvelocityAfterKill);
				if (life == 3) {
					i.increaceScore(numberOfPointsPerKill);
					life--;
					velocity.x = 0;
				}
				else if (life == 2) {
					life--;
					velocity.x += shellSpeed;
				}
				else if (life == 1) {
					life++;
					velocity.x = 0;
				}
			}
			else
			{
				p.setLife(false);
			}
}

void Turtle::setAnimationSettings(sf::Vector2i size, sf::Vector2i firstFrameCoordinates, int countOfFrames, int rangeBetweenFrames, float speed)
{
	animation.setAnimationParametres(size, firstFrameCoordinates, countOfFrames, rangeBetweenFrames, speed);
	enemyHitbox.height = size.y;
	enemyHitbox.width = size.x;
}

void Turtle::draw(sf::RenderWindow& window)
{
	window.draw(animation.getSprite());
}