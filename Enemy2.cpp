#include "Enemy2.h"

void Enemy2::init()
{
	shape[0] = "   天天   ";
	shape[1] = "天太∞太天";
	shape[2] = "   天天   ";
}

void Enemy2::Enemymove2(int x, int y)
{
	Speed++;

	if (Speed % 1 == 0)
	{

		if (x > enemy2x)
		{
			enemy2x++;
		}
		if (x < enemy2x)
		{
			enemy2x--;
		}
		if (y > enemy2y)
		{
			enemy2y++;
		}
		if (y < enemy2y)
		{
			enemy2y--;
		}

	}
}

void Enemy2::RenderEnemy()
{
	char eneme_hp[10];
	_itoa_s(enemy2hp, eneme_hp, 10);

	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(enemy2x, enemy2y + i, shape[i], RED);
	}
	DoubleBuffer::Get()->WriteBuffer(32, 0, "瞳 羹溘", WHITE);
	DoubleBuffer::Get()->WriteBuffer(37, 0, eneme_hp, RED);
}

void Enemy2::Respawn()
{
	enemy2x = (rand() % 2 == 0) ? 0 : 40;
	enemy2y = 28;
	enemy2hp = 10;
	enemy2act = true;
}
