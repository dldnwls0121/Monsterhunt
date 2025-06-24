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
				if (Player->hp <= 0) // �÷��̾ ���� �� ���� ����, ��ü�� �� ����
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
