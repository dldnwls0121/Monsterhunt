#include "SHOP.h"
#include "Color.h"
#include "Datamanager.h"
#include "Utility.h"

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
		
		PLAYER * player = DataManager::Get()->currentplayer;
		if (arrowy == 20)
		{
			player->playermoney -= Hppotion;
			DoubleBuffer::Get()->WriteBuffer(20, 2, "고맙다냥", WHITE);
		}
		else if (arrowy == 25)
		{
			DoubleBuffer::Get()->WriteBuffer(20, 5, "고맙다냥", WHITE);
		}
		else if (arrowy == 30)
		{
			DoubleBuffer::Get()->WriteBuffer(20, 5, "고맙다냥", WHITE);
		}
		else if (arrowy == 35)
		{
			SceneManager::Get()->Setscene(MENU);
		}
		
		
	}
}
#pragma region shop
//void Shop::Progress()
//{
//	// 방향키 처리
//	if (GetAsyncKeyState(VK_UP) & 0x8000)
//	{
//		if (arrowy > 20)
//		{
//			arrowy -= 5;
//			Prev_arrowy += 5;
//		}
//	}
//	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
//	{
//		if (arrowy < 35)
//		{
//			arrowy += 5;
//			Prev_arrowy -= 5;
//		}
//	}
//
//	// 아이템 판매 처리
//	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
//	{
//		PLAYER* player = DataManager::Get()->currentplayer;
//
//		if (!player) return; // 혹시 없을 경우 방어 코드
//
//		switch (arrowy)
//		{
//		case 20: // 체력 포션
//			if (player->playermoney >= Hppotion)
//			{
//				player->playermoney -= Hppotion;
//				player->hp += 20; // 예시: 체력 20 회복
//				DoubleBuffer::Get()->WriteBuffer(20, 2, "체력 포션 구매!", WHITE);
//			}
//			break;
//		case 25: // 공격력 포션
//			if (player->playermoney >= Atkpotion)
//			{
//				player->playermoney -= Atkpotion;
//				player->atk += 5;
//				DoubleBuffer::Get()->WriteBuffer(20, 5, "공격력 증가!", WHITE);
//			}
//			break;
//		case 30: // 방어력 포션
//			if (player->playermoney >= Defpotion)
//			{
//				player->playermoney -= Defpotion;
//				player->def += 5;
//				DoubleBuffer::Get()->WriteBuffer(20, 5, "방어력 증가!", WHITE);
//			}
//			break;
//		case 35: // 메뉴 화면
//			SceneManager::Get()->Setscene(MENU);
//			break;
//		}
//	}
//}

#pragma endregion

void Shop::Render()
{
	DataManager::Get()->SetPlayer();

	char player_gold[10];
	int playermoney = DataManager::Get()->currentplayer->playermoney;

	_itoa_s(playermoney, player_gold, 10);

	for (int i = 0; i < 12; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y+i, shape[i], WHITE);
	}
	DoubleBuffer::Get()->WriteBuffer(arrowx, arrowy , arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(arrowx, Prev_arrowy, Prev_arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 20, "체력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 25, "공격력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 30, "방어력 포션", WHITE);
	DoubleBuffer::Get()->WriteBuffer(16, 35, "메뉴 화면으로", WHITE);
	DoubleBuffer::Get()->WriteBuffer(0, 0, "소지금 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 0, player_gold, YELLOW);
}



Shop::~Shop()
{
}
 