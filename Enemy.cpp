#include "Enemy.h"
#include "Collision.h"

float& Enemy::getXvelocity()
{
	return velocity.x;
}

float& Enemy::getYvelocity()
{
	return velocity.y;
}

void Enemy::setYvelocity(float velocityY)
{
	this->velocity.y = velocityY;
}

void Enemy::setOnGround(bool val)
{
	this->onGround = val;
}

void Enemy::setLife(int life)
{
	this->life = life;
}

sf::FloatRect Enemy::getEnemyHitbox()
{
	return enemyHitbox;
}

void Enemy::setEnemyHitboxLeft(float enemyHitboxLeft)
{
	this->enemyHitbox.left = enemyHitboxLeft;
}

void Enemy::setEnemyHitboxTop(float enemyHitboxTop)
{
	this->enemyHitbox.top = enemyHitboxTop;
}
