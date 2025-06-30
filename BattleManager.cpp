#include "BattleManager.h"

BattleManager* BattleManager::instance = nullptr;

void BattleManager::Playerstage1()
{
	Enemy& enemies = *DataManager::Get()->currentenemy;
	PLAYER& player = *DataManager::Get()->currentplayer;


	//�÷��̾� ����
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (player.dir == LEFT)
		{
			player.dir = LSPACE;
			if (enemies.enemyx <= player.x && player.x - 4 <= enemies.enemyx)
			{
				enemies.enemyhp -= player.atk;

				if (enemies.enemyhp <= 0)
				{
					enemies.enemyact = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemycount)
					{
						enemies.Respawn();
					}
					else if (DataManager::Get()->killCount >= Enemycount)
					{
						enemies.enemyact = false;
					}
				}
			}
		}

		else if (player.dir == RIGHT)
		{
			player.dir = RSPACE;
			if (enemies.enemyx >= player.x && player.x + 4 >= enemies.enemyx)
			{
				enemies.enemyhp -= player.atk;
				if (enemies.enemyhp <= 0)
				{
					enemies.enemyact = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemycount)
					{
						enemies.Respawn();

					}
					else if (DataManager::Get()->killCount >= Enemycount)
					{
						enemies.enemyact = false;
					}
				}
			}
		}
	}

	else
	{
		if (player.dir == RSPACE)
		{
			player.dir = RIGHT;
		}
		if (player.dir == LSPACE)
		{
			player.dir = LEFT;
		}
	}

	//�÷��̾ �������� ���� ���
	if (!enemies.enemyact)
	{
		return;
	}
	if (player.x == enemies.enemyx)
	{
		player.hp -= ( enemies.enemydmg - player.def );
		if (player.hp <= 0)
		{
			player.dir = DIE;
			enemies.enemyact = false;

			return;
		}
	}
}

void BattleManager::Nextstage2()
{
	DoubleBuffer::Get()->WriteBuffer(20, 0, " /8 óġ ��", YELLOW);
	if (DataManager::Get()->killCount == Enemycount)
	{

		DoubleBuffer::Get()->WriteBuffer(10, 10, "��� ���͸� óġ�߽��ϴ�! ", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "���� ���������� ������ Enter�� �����ּ���!", YELLOW);
		if (GetAsyncKeyState(VK_RETURN))
		{
			DataManager::Get()->ReleaseEnemy();
			DataManager::Get()->killCount = 0;
			SceneManager::Get()->Setscene(STAGE2);
		}
	}
}

void BattleManager::Playerstage2()
{

	Enemy2& enemies2 = *DataManager::Get()->currentenemy2;
	PLAYER& player = *DataManager::Get()->currentplayer;
	
	//�÷��̾� ����
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (player.dir == LEFT)
		{
			player.dir = LSPACE;
			if (enemies2.enemy2x <= player.x && player.x - 4 <= enemies2.enemy2x)
			{
				enemies2.enemy2hp -= player.atk;

				if (enemies2.enemy2hp <= 0)
				{
					enemies2.enemy2act = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemy2count)
					{
						enemies2.Respawn();

					}
					else if (DataManager::Get()->killCount >= Enemy2count)
					{
						enemies2.enemy2act = false;
					}
				}
			}

		}

		else if (player.dir == RIGHT)
		{
			player.dir = RSPACE;
			if (enemies2.enemy2x >= player.x && player.x + 4 >= enemies2.enemy2x)
			{
				enemies2.enemy2hp -= player.atk;

				if (enemies2.enemy2hp <= 0)
				{
					enemies2.enemy2act = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemy2count)
					{
						enemies2.Respawn();

					}
					else if (DataManager::Get()->killCount >= Enemy2count)
					{
						enemies2.enemy2act = false;
					}
				}
			}
		}
	}

	else
	{
		if (player.dir == RSPACE)
		{
			player.dir = RIGHT;
		}
		if (player.dir == LSPACE)
		{
			player.dir = LEFT;
		}
	}

	//�÷��̾ �������� ���� ���
	if (!enemies2.enemy2act)
	{
		return;
	}

	if (player.x == enemies2.enemy2x)
	{
		player.hp -= (enemies2.enemy2dmg - player.def);
		if (player.hp <= 0)
		{
			player.dir = DIE;
			enemies2.enemy2act = false;

			return;
		}
	}

}

void BattleManager::NextBoss()
{
	DoubleBuffer::Get()->WriteBuffer(20, 0, " /5 óġ ��", YELLOW);
	if (DataManager::Get()->killCount == 5)
	{
		
		DoubleBuffer::Get()->WriteBuffer(10, 10, "��� ���������� Ŭ�����ϼ̽��ϴ�! ", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "������ �����ϸ� Enter�� �����ּ���!", YELLOW);

		if (GetAsyncKeyState(VK_RETURN))
		{
	
			DataManager::Get()->ReleaseEnemy2();
			DataManager::Get()->killCount = 0;
			SceneManager::Get()->Setscene(BOSS);

		}
	}
}

void BattleManager::PlayerBoss()
{
	Boss& boss = *DataManager::Get()->currentboss;
	PLAYER& player = *DataManager::Get()->currentplayer;


	//�÷��̾� ����
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (player.dir == LEFT)
		{
			player.dir = LSPACE;
			if (boss.bossx <= player.x && player.x - 4 <= boss.bossx)
			{
				boss.bosshp -= player.atk;

				if (boss.bosshp <= 0)
				{
					boss.bossact = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount == 1)
					{
						boss.bossact = false;
					}
				}
			}

		}

		else if (player.dir == RIGHT)
		{
			player.dir = RSPACE;
			if (boss.bossx >= player.x && player.x + 4 >= boss.bossx)
			{
				boss.bosshp -= player.atk;

				if (boss.bosshp <= 0)
				{
					boss.bossact = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;

					if (DataManager::Get()->killCount == 1)
					{
						boss.bossact = false;
					}
				}
			}
		}
	}

	else
	{
		if (player.dir == RSPACE)
		{
			player.dir = RIGHT;
		}
		if (player.dir == LSPACE)
		{
			player.dir = LEFT;
		}
	}

	//�÷��̾ �������� ���� ���
	if (!boss.bossact)
	{
		return;
	}
	boss.bossattackcount++;

	// ���� ����: bossattackcount�� 10 �̻��� �� �� ���� ����
	if (boss.bossattackcount >= 2)
	{

		for (int i = 0; i < Boss_attack; i++)
		{
			if (!boss.attack_active[i])
			{
				boss.attack_x[i] = boss.bossx - 1;
				boss.attack_y[i] = 28 + rand() % 4;
				boss.attack_active[i] = true;
				boss.attack_shape[i] = "��";
				break;
			}

			boss.attack_x[i]--;
			if (boss.attack_x[i] < 0)
			{
				boss.attack_active[i] = false;
			}

		}

		boss.bossattackcount = 0;
	}
	for (int i = 0; i < Boss_attack; i++)
	{
		if (boss.attack_active[i])
		{
			if (player.x + 2 >= boss.attack_x[i] && boss.attack_x[i] >= player.x - 2 
				&& boss.attack_y[i] <= player.y + 3 && boss.attack_y[i] >= player.y - 3)
			{
				player.hp -= (boss.bossdmg - player.def);
				boss.attack_active[i] = false;
				

				if (boss.attack_x[i] <= 0)
				{
					boss.attack_active[i] = false; // ȭ�� ������ ������ ��Ȱ��ȭ
				}
				if (player.hp <= 0)
				{
					player.dir = DIE;
					boss.bossact = false;
					boss.attack_active[i] = false;
					
				}
			}
		}

	}

}



void BattleManager::Stage1PlayerDie()
{
	if (DataManager::Get()->currentplayer->hp <= 0)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "�÷��̾ ����Ͽ����ϴ�", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "�޴��� ���ư��Ƿ��� Enter�� �����ּ���", YELLOW);
		if (GetAsyncKeyState(VK_RETURN))
		{
			SceneManager::Get()->Setscene(MENU);
			DataManager::Get()->currentplayer->hp = 50;
			DataManager::Get()->currentplayer->dir = LEFT;
			DataManager::Get()->currentplayer->atk = 10;
			DataManager::Get()->currentplayer->def = 5;
			DataManager::Get()->currentplayer->playermoney = 500;
			DataManager::Get()->killCount = 0;
			if (DataManager::Get()->currentenemy != nullptr)
			{

				DataManager::Get()->currentenemy->enemyhp = 10;
				DataManager::Get()->currentenemy->enemyx = 40;
				DataManager::Get()->currentenemy->enemyy = 28;
				DataManager::Get()->currentenemy->enemydmg = 5;
				DataManager::Get()->currentenemy->enemyact = true;


			}
		}


	}
}

void BattleManager::Stage2PlayerDie()
{
	if (DataManager::Get()->currentplayer->hp <= 0)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "�÷��̾ ����Ͽ����ϴ�", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "�޴��� ���ư��Ƿ��� Enter�� �����ּ���", YELLOW);
		if (GetAsyncKeyState(VK_RETURN))
		{
			SceneManager::Get()->Setscene(MENU);
			DataManager::Get()->currentplayer->hp = 50;
			DataManager::Get()->currentplayer->dir = LEFT;
			DataManager::Get()->currentplayer->atk = 10;
			DataManager::Get()->currentplayer->def = 5;
			DataManager::Get()->currentplayer->playermoney = 500;
			DataManager::Get()->killCount = 0;
			if (DataManager::Get()->currentenemy != nullptr)
			{

				DataManager::Get()->currentenemy2->enemy2hp = 20;
				DataManager::Get()->currentenemy2->enemy2x = 40;
				DataManager::Get()->currentenemy2->enemy2y = 28;
				DataManager::Get()->currentenemy2->enemy2dmg = 5;
				DataManager::Get()->currentenemy2->enemy2act = true;

			}
		}


	}
}

void BattleManager::BossPlayerDie()
{
	if (DataManager::Get()->currentplayer->hp <= 0)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "�÷��̾ ����Ͽ����ϴ�", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "�޴��� ���ư��Ƿ��� Enter�� �����ּ���", YELLOW);
		if (GetAsyncKeyState(VK_RETURN))
		{
			SceneManager::Get()->Setscene(MENU);
			DataManager::Get()->currentplayer->hp = 50;
			DataManager::Get()->currentplayer->dir = LEFT;
			DataManager::Get()->currentplayer->atk = 10;
			DataManager::Get()->currentplayer->def = 5;
			DataManager::Get()->currentplayer->playermoney = 500;
			DataManager::Get()->killCount = 0;

			if (DataManager::Get()->currentenemy != nullptr)
			{
				DataManager::Get()->currentboss->bosshp = 20;
				DataManager::Get()->currentboss->bossx = 40;
				DataManager::Get()->currentboss->bossy = 28;
				DataManager::Get()->currentboss->bossdmg = 5;
				DataManager::Get()->currentboss->bossact = true;
			}
		}


	}
}

void BattleManager::BossClear()
{
	DoubleBuffer::Get()->WriteBuffer(20, 0, " /1 óġ ��", YELLOW);
	if (DataManager::Get()->killCount == 1)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "��� ���������� Ŭ�����ϼ̽��ϴ�! ", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "������ �����ϸ� Enter�� �����ּ���!", YELLOW);

		if (GetAsyncKeyState(VK_RETURN))
		{
			DataManager::Get()->ReleaseBoss();
			DataManager::Get()->ReleasePlayer();
			exit(1);

		}
	}
}
