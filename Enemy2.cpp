#include "Enemy2.h"

void Enemy2::init()
{
	shape[0] = "   �Ѥ�   ";
	shape[1] = "�ѤӡۤӤ�";
	shape[2] = "   �Ѥ�   ";
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
	DoubleBuffer::Get()->WriteBuffer(32, 0, "�� ü��", WHITE);
	DoubleBuffer::Get()->WriteBuffer(37, 0, eneme_hp, RED);
}

void Enemy2::Respawn()
{
	enemy2x = (rand() % 2 == 0) ? 0 : 40;
	enemy2y = 28;
	enemy2hp = 10;
	enemy2act = true;
}
