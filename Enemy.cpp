#include "Enemy.h"
#include "Color.h"
Enemy::Enemy()
{
	enemyx = 0;
	enemyy = 28;
	enemydmg = 5;
	enemyact = true;
	enemyhp = 10;
}


void Enemy::init()
{
	enemyx = (rand() % 2 == 0) ? 0 : 40;
	enemyy = 28;
	enemydmg = 5;
	enemyact = true;
	Allenemydie = false;
	enemyhp = 10;

	shape[0] = " 天天天";
	shape[1] = "太 ∞ 太";
	shape[2] = "太~~~~太";
	shape[3] = " 天天天";
}

int Speed = 0;
void Enemy::Enemymove(int x,int y)
{

	Speed++;

	if (Speed % 3 == 0)
	{

		if (x > enemyx)
		{
			enemyx++;
		}
		if (x < enemyx)
		{
			enemyx--;
		}
		if (y > enemyy)
		{
			enemyy++;
		}
		if (y < enemyy)
		{
			enemyy--;
		}

	}
}


void Enemy::RenderEnemy()
{
	char emyhp[10];

	_itoa_s(enemyhp, emyhp, 10);

	
		if (enemyact == true)
		{
			for (int i = 0; i < 4; i++)
			{
				DoubleBuffer::Get()->WriteBuffer(enemyx, enemyy + i, shape[i], BLUE);
			}
		}
	
	
	DoubleBuffer::Get()->WriteBuffer(32, 0,"瞳 羹溘 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(37, 0, emyhp, RED);
}