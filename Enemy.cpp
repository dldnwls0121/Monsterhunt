#include "Enemy.h"
#include "Color.h"


void Enemy::init()
{
	shape[0] = " �ѤѤ�";
	shape[1] = "�� �� ��";
	shape[2] = "��~~~~��";
	shape[3] = " �ѤѤ�";
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