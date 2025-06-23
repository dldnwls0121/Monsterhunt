#include "SHOP.h"
#include "Color.h"
#include "Datamanager.h"

void Shop::Init()
{
	shape[0] = "             ■        ■";
	shape[1] = "           ■■■    ■■■";
	shape[2] = "           ■■■■■■■■";
	shape[3] = "       ■■                ■■";
	shape[4] = "         ■    ■     ■   ■";
	shape[5] = "     ■■■                ■■■";
	shape[6] = "         ■     ↖↗↖↗   ■";
	shape[7] = "       ■■                ■■";
	shape[8] = "           ■■        ■■";
	shape[9] = "               ■■■■";
	shape[10] = "             ■       ■";
	shape[11] = "■■■■■■■■■■■■■■■■■■■■";
}


void Shop::Progress()
{
	if (GetAsyncKeyState(VK_UP))
	{
		arrowy -= 5;
		if (arrowy <= 20)
		{
			arrowy = 20;
		}

	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		arrowy += 5;
		if (arrowy >= 35)
		{
			arrowy = 35;
		}
	}

	int speed = 0;
	if (GetAsyncKeyState(VK_RETURN))
	{
		speed++;
		if (arrowy == 20)
		{
			if (speed % 10 == 0)
			{
				player = 
				Player.playermoney -= Hppotion;
				DoubleBuffer::Get()->WriteBuffer(20, 2, "고맙다냥", WHITE);

				speed = 0;
			}
		}
		if (arrowy == 25)
		{
			DoubleBuffer::Get()->WriteBuffer(20, 5, "고맙다냥", WHITE);
		}
		if (arrowy == 30)
		{
			DoubleBuffer::Get()->WriteBuffer(20, 5, "고맙다냥", WHITE);
		}
		if (arrowy == 35)
		{
			SceneManager::Get()->Setscene(MENU);
		}
		

	}
}

void Shop::Render()
{
	for (int i = 0; i < 12; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y+i, shape[i], WHITE);
	}
	DoubleBuffer::Get()->WriteBuffer(arrowx,arrowy ,arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 20, "체력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 25, "공격력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 30, "방어력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 35, "메뉴 화면으로", WHITE);
}
