#include "Collision.h"

int Collision::collision(bool flag, Entity& e, GameMap& map)
{
	const int pixelsInTile = 16;
	for (int i = e.getEntityHitbox().top / pixelsInTile; i < (e.getEntityHitbox().top + e.getEntityHitbox().height) / pixelsInTile; i++)
		for (int j = e.getEntityHitbox().left / pixelsInTile; j < (e.getEntityHitbox().left + e.getEntityHitbox().width) / pixelsInTile; j++)
		{
			if (map.GetLethality(j, i))
				e.setLife(0);
			if (map.get_Hardness(j,i))
			{
				if (e.getYvelocity() > 0 && flag == 1)
				{
					e.setEntityHitboxTop(i * 16 - e.getEntityHitbox().height);
					e.setYvelocity(0);
					e.setOnGround(true);
				}
				if (e.getYvelocity() < 0 && flag == 1)
				{
					if (map.GetBreakable(j, i))
						map.SetEmptySpace(j, i);
					e.setEntityHitboxTop(i * pixelsInTile + pixelsInTile);
					e.setYvelocity(0);
					if (map.IsBonus(j, i) == true) {
						map.SetBrick(j, i);
						return 2;
					}
				}
				if (e.getXvelocity() > 0 && flag == 0)
				{
					e.setEntityHitboxLeft(j * pixelsInTile - e.getEntityHitbox().width);
					return 1;
				}
				if (e.getXvelocity() < 0 && flag == 0)
				{
					e.setEntityHitboxLeft(j * pixelsInTile + pixelsInTile);
					return 1;
				}
			}

		}
	return 0;
}