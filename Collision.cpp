#include "Collision.h"

void Collision::collision(bool flag, Person& p, GameMap& map)
{
	const int pixelsInTile = 16;
	for (int i = p.getPersonHitbox().top / pixelsInTile; i < (p.getPersonHitbox().top + p.getPersonHitbox().height) / pixelsInTile; i++)
		for (int j = p.getPersonHitbox().left / pixelsInTile; j < (p.getPersonHitbox().left + p.getPersonHitbox().width) / pixelsInTile; j++)
		{
			if (map.GetLethality(j, i))
				p.Death(250);
			if (map.get_Hardness(j,i))
			{
				if (p.getYvelocity() > 0 && flag == 1)
				{
					p.setPersonHitboxTop(i * 16 - p.getPersonHitbox().height);
					p.setYvelocity(0);
					p.setOnGround(true);
				}
				if (p.getYvelocity() < 0 && flag == 1)
				{
					if (map.GetBreakable(j, i))
						map.SetEmptySpace(j, i);
					p.setPersonHitboxTop(i * pixelsInTile + pixelsInTile);
					p.setYvelocity(0);
				}
				if (p.getXvelocity() > 0 && flag == 0)
				{
					p.setPersonHitboxLeft(j * pixelsInTile - p.getPersonHitbox().width);
				}
				if (p.getXvelocity() < 0 && flag == 0)
				{
					p.setPersonHitboxLeft(j * pixelsInTile + pixelsInTile);
				}
			}

		}
}

bool Collision::npcCollision(bool flag, Enemy& n, GameMap& map)
{
	const int pixelsInTile = 16;
	for (int i = n.getEnemyHitbox().top / pixelsInTile; i < (n.getEnemyHitbox().top + n.getEnemyHitbox().height) / pixelsInTile; i++)
		for (int j = n.getEnemyHitbox().left / pixelsInTile; j < (n.getEnemyHitbox().left + n.getEnemyHitbox().width) / pixelsInTile; j++) {
			if (map.GetLethality(j, i))
				n.setLife(0);
			if (map.get_Hardness(j, i) == true)
			{
				if (n.getYvelocity() > 0 && flag == 1)
				{
					n.setEnemyHitboxTop(i * 16 - n.getEnemyHitbox().height);
					n.setYvelocity(0);
					n.setOnGround(true);
				}
				if (n.getYvelocity() < 0 && flag == 1)
				{
					n.setEnemyHitboxTop(i * 16 + 16);
					n.setYvelocity(0);
				}
				if (n.getXvelocity() > 0 && flag == 0)
				{
					n.setEnemyHitboxLeft(j * 16 - n.getEnemyHitbox().width);
					return true;
				}
				else if (n.getXvelocity() < 0 && flag == 0)
				{
					n.setEnemyHitboxLeft(j * 16 + 16);
					return true;
				}
			}
		}
	return false;
}