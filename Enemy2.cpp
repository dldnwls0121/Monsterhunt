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

	if (Speed % 3 == 0)
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
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(enemy2x, enemy2y + i, shape[i], RED);
	}
}

void Enemy2::Respawn()
{
}
