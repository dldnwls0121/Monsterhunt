#include "SHOP.h"
#include "Color.h"
#include "Datamanager.h"
#include "Utility.h"

void Shop::Init()
{
	shape[0] = "             ��        ��";
	shape[1] = "           ����    ����";
	shape[2] = "           ���������";
	shape[3] = "       ���                ���";
	shape[4] = "         ��    ��     ��   ��";
	shape[5] = "     ����                ����";
	shape[6] = "         ��     �آ֢آ�   ��";
	shape[7] = "       ���                ���";
	shape[8] = "           ���        ���";
	shape[9] = "               �����";
	shape[10] = "             ��       ��";
	shape[11] = "���������������������";

}


void Shop::Progress()
{
	if (GetAsyncKeyState(VK_UP))
	{
	
			if (arrowy > 20)
			{
				arrowy -= 5;
				Prev_arrowy += 5;
			}
		


	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		
		if (arrowy < 35)
		{
			arrowy += 5;
			Prev_arrowy -= 5;
		}
	}

	
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		
		
		if (arrowy == 20)
		{
			if (DataManager::Get()->currentplayer->playermoney >= Hppotion)
			{
				DataManager::Get()->currentplayer->playermoney -= Hppotion;
				DataManager::Get()->currentplayer->Hppotion += 1;
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���ٳ�", WHITE);
			}
			else
			{
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���� �����ϴ�!", WHITE);
			}
	
		}
		else if (arrowy == 25)
		{
			if (DataManager::Get()->currentplayer->playermoney >= Strpotion)
			{
				DataManager::Get()->currentplayer->playermoney -= Strpotion;
				DataManager::Get()->currentplayer->Atkpotion += 1;
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���ٳ�", WHITE);
			}
			else
			{
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���� �����ϴ�!", WHITE);
			}
		}
		else if (arrowy == 30)
		{
			if (DataManager::Get()->currentplayer->playermoney >= Defpotion)
			{
				DataManager::Get()->currentplayer->playermoney -= Defpotion;
				DataManager::Get()->currentplayer->Defpotion += 1;
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���ٳ�", WHITE);
			}
			else
			{
				DoubleBuffer::Get()->WriteBuffer(20, 2, "���� �����ϴ�!", WHITE);
			}
		}
		else if (arrowy == 35)
		{
			SceneManager::Get()->Setscene(MENU);
		}
		
		
	}
}


void Shop::Render()
{

	char player_gold[10];
	int playermoney = DataManager::Get()->currentplayer->playermoney;

	_itoa_s(playermoney, player_gold, 10);

	for (int i = 0; i < 12; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y+i, shape[i], WHITE);
	}
	DoubleBuffer::Get()->WriteBuffer(arrowx, arrowy , arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(arrowx, Prev_arrowy, Prev_arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 20, "ü�� ����", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 25, "���ݷ� ����", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 30, "���� ����", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 35, "�޴� ȭ������", WHITE);
	DoubleBuffer::Get()->WriteBuffer(0, 0, "������ : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 0, player_gold, YELLOW);
}



Shop::~Shop()
{
}
 