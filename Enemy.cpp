#include "Enemy.h"
#include "Color.h"


void Enemy::init()
{
	shape[0] = " 天天天";
	shape[1] = "太 ∞ 太";
	shape[2] = "太~~~~太";
	shape[3] = " 天天天";
}

int Speed = 0;
void Enemy::Enemymove(int x)
{

	Speed++;

	if (Speed % 2 == 1)
	{

		if (x > enemyx)
		{
			enemyx++;
		}
		if (x < enemyx)
		{
			enemyx--;
		}

	}
}


void Enemy::Enemyprt()
{

	if (enemyact == true)
	{
		for (int i = 0; i < 4; i++)
		{
			DoubleBuffer::Get()->WriteBuffer(enemyx, enemyy + i, shape[i], BLUE);
		}
	}

}