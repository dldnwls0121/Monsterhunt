#include "Boss.h"
#include "Datamanager.h"

void Boss::init()
{
		  
	shape[0][0] =  "      กแกแกแ  กแกแ  กแกแกแ";
	shape[0][1] =  "      กแกแกแ  กแกแ  กแกแกแ";
	shape[0][2] =  "      กแกแกแ  กแกแ  กแกแกแ";
	shape[0][3] =  "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[0][4] =  "กแกแกแกแกแกแ กแ  กแ กแกแกแ";
	shape[0][5] =  "กแกแกแกแ    กแ l  กแ    กแ";
	shape[0][6] =  "      กแกแกแ กแ  กแ กแกแกแ";
	shape[0][7] =  "      กแกแกแกแกแกแกแกแกแกแ";

	shape[1][0] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[1][1] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[1][2] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[1][3] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[1][4] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[1][5] = "กแกแกแกแกแ  กแ l   กแ   กแ";
	shape[1][6] = "      กแกแกแกแกแกแกแกแกแกแ";
	shape[1][7] = "      กแกแกแกแกแกแกแกแกแกแ";

	shape[2][0] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[2][1] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[2][2] = "      กแกแกแ  กแกแ  กแกแกแ";
	shape[2][3] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[2][4] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[2][5] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	shape[2][6] = "      กแกแกแกแกแกแกแกแกแกแ";
	shape[2][7] = "      กแกแกแกแกแกแกแกแกแกแ";

	Dieshape[0] = "      กแกแกแ  กแกแ  กแกแกแ";
	Dieshape[1] = "      กแกแกแ  กแกแ  กแกแกแ";
	Dieshape[2] = "      กแกแกแ  กแกแ  กแกแกแ";
	Dieshape[3] = "กแกแกแกแกแกแกแกแกแกแกแกแกแ";
	Dieshape[4] = "กแกแกแกแกแกแ กแ  กแ กแกแกแ";
	Dieshape[5] = "กแกแกแกแ       กแ       กแ";
	Dieshape[6] = "      กแกแกแ กแ  กแ กแกแกแ";
	Dieshape[7] = "      กแกแกแกแกแกแกแกแกแกแ";


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
		DoubleBuffer::Get()->WriteBuffer(32, 0, "บธฝบ รผทย", WHITE);
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




