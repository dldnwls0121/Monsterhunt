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
	//if (Player != nullptr && enemy != nullptr)//�̰� ���� ����
	//{
	//	Player->Playermove(*enemy);
	//
	//	if (enemy->enemyact == true)
	//	{
	//		if (Player->x == enemy->enemyx)
	//		{
	//			Player->hp -= enemy->enemydmg;
	//			if (Player->hp <= 0) // �÷��̾ ���� �� ���� ����, ��ü�� �� ����
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
