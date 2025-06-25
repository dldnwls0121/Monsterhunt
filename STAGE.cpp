#include "STAGE.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"
#include "Datamanager.h"

Enemy* enemy = new Enemy;


void Stage::Init()
{
	
	DataManager::Get()->currentplayer->init();
	enemy->init();
}



void Stage::Progress()
{
	cout << " " << endl;
	//if (Player != nullptr && enemy != nullptr)//이거 해제 수정
	//{
	//	Player->Playermove(*enemy);
	//
	//	if (enemy->enemyact == true)
	//	{
	//		if (Player->x == enemy->enemyx)
	//		{
	//			Player->hp -= enemy->enemydmg;
	//			if (Player->hp <= 0) // 플레이어가 죽을 시 게임 종료, 객체들 다 해제
	//			{
	//				enemy->enemyact = false;
	//				Player->dir = DIE;
	//
	//			}
	//		}
	//	}
	//}
}


void Stage::Render()
{

	DataManager::Get()->currentplayer->Renderplayer();
	enemy->RenderEnemy();
}
