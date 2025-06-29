#include "Boss.h"
#include "Datamanager.h"

void Boss::init()
{
		  
	shape[0][0] =  "      ■■■  ■■  ■■■";
	shape[0][1] =  "      ■■■  ■■  ■■■";
	shape[0][2] =  "      ■■■  ■■  ■■■";
	shape[0][3] =  "■■■■■■■■■■■■■";
	shape[0][4] =  "■■■■■■ ■  ■ ■■■";
	shape[0][5] =  "■■■■    ■ l  ■    ■";
	shape[0][6] =  "      ■■■ ■  ■ ■■■";
	shape[0][7] =  "      ■■■■■■■■■■";

	shape[1][0] = "      ■■■  ■■  ■■■";
	shape[1][1] = "      ■■■  ■■  ■■■";
	shape[1][2] = "      ■■■  ■■  ■■■";
	shape[1][3] = "■■■■■■■■■■■■■";
	shape[1][4] = "■■■■■■■■■■■■■";
	shape[1][5] = "■■■■■  ■ l   ■   ■";
	shape[1][6] = "      ■■■■■■■■■■";
	shape[1][7] = "      ■■■■■■■■■■";

	shape[2][0] = "      ■■■  ■■  ■■■";
	shape[2][1] = "      ■■■  ■■  ■■■";
	shape[2][2] = "      ■■■  ■■  ■■■";
	shape[2][3] = "■■■■■■■■■■■■■";
	shape[2][4] = "■■■■■■■■■■■■■";
	shape[2][5] = "■■■■■■■■■■■■■";
	shape[2][6] = "      ■■■■■■■■■■";
	shape[2][7] = "      ■■■■■■■■■■";

	Dieshape[0] = "      ■■■  ■■  ■■■";
	Dieshape[1] = "      ■■■  ■■  ■■■";
	Dieshape[2] = "      ■■■  ■■  ■■■";
	Dieshape[3] = "■■■■■■■■■■■■■";
	Dieshape[4] = "■■■■■■ ■  ■ ■■■";
	Dieshape[5] = "■■■■       ■       ■";
	Dieshape[6] = "      ■■■ ■  ■ ■■■";
	Dieshape[7] = "      ■■■■■■■■■■";


}






void Boss::RenderBoss()
{
	if (DataManager::Get()->currentboss != nullptr)
	{
		char boss_hp[10];
		_itoa_s(bosshp, boss_hp, 10);
		if (bosshp <= 0)
		{
			for (int i = 0; i < 8; i++)
			{
				DoubleBuffer::Get()->WriteBuffer(bossx, bossy + i, Dieshape[i], RED);
			}
			return;
		}

		Speed++;

		if (Speed >= 10)
		{
			aniindex++;
			if (aniindex >= 3)
			{
				aniindex = 0;

			}
			Speed = 0;
		}

		for (int i = 0; i < 8; i++)
		{
			
				DoubleBuffer::Get()->WriteBuffer(bossx, bossy + i, shape[aniindex][i], RED);
			
			
		}
		DoubleBuffer::Get()->WriteBuffer(32, 0, "보스 체력", WHITE);
		DoubleBuffer::Get()->WriteBuffer(37, 0, boss_hp, RED);

		for (int i = 0; i < Boss_attack; i++)
		{
			if (attack_active[i]==true)
			{
				DoubleBuffer::Get()->WriteBuffer(attack_x[i],attack_y[i], attack_shape[i], RED);
			}

		}


	}


}




