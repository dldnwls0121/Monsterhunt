#include "STAGE.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"

PLAYER* Player = new PLAYER;
Enemy* enemy = new Enemy;

void Stage::Init()
{
	Player->init();
	enemy->init();
	
}

void Stage::Progress()
{
	if (Player != nullptr && enemy != nullptr)
	{
		Player->Playermove(*enemy);

		if (enemy->enemyact == true)
		{
			if (Player->x == enemy->enemyx)
			{
				Player->hp -= enemy->enemydmg;
				if (Player->hp <= 0) // 플레이어가 죽을 시 게임 종료, 객체들 다 해제
				{
					enemy->enemyact = false;
					Player->dir = DIE;

				}
			}
		}
	}
}

void Stage::Render()
{
	Player->Renderplayer();
	enemy->RenderEnemy();
}
