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

	}
}


void Enemy::Enemyprt()
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

	DoubleBuffer::Get()->WriteBuffer(32, 0,"�� ü�� : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(37, 0, emyhp, RED);
}