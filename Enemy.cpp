#include "Enemy.h"
#include "Color.h"
#include "Datamanager.h"


void Enemy::init()
{


	shape[0] = " �ѤѤ�";
	shape[1] = "�� �� ��";
	shape[2] = "��~~~~��";
	shape[3] = " �ѤѤ�";
}



void Enemy::Enemymove(int x,int y)
{

	Speed++;

	if (Speed % 2 == 0)
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
	if (DataManager::Get()->currentenemy != nullptr)
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


		DoubleBuffer::Get()->WriteBuffer(32, 0, "�� ü�� : ", WHITE);
		DoubleBuffer::Get()->WriteBuffer(37, 0, emyhp, RED);
	}


}

void Enemy::Respawn()
{
	enemyx = (rand() % 2 == 0) ? 0 : 40;
	enemyy = 28;
	enemyhp = 10;
	enemyact = true;
}