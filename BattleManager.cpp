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
					else if (DataManager::Get()->killCount == Enemycount)
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
					else if (DataManager::Get()->killCount == Enemycount)
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
		player.hp -= enemies.enemydmg;
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
	if (DataManager::Get()->killCount == Enemycount)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "��� ���͸� óġ�߽��ϴ�! ", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "���� ���������� ������ Enter�� �����ּ���!", YELLOW);

		if (GetAsyncKeyState(VK_RETURN))
		{
			DataManager::Get()->ReleaseEnemy();
			DataManager::Get()->killCount = 0;
			DataManager::Get()->SetEnemy2();
			SceneManager::Get()->Setscene(STAGE2);


		}
	}
}

void BattleManager::Playerstage2()
{

	Enemy2& enemies = *DataManager::Get()->currentenemy2;
	PLAYER& player = *DataManager::Get()->currentplayer;

	//�÷��̾� ����
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (player.dir == LEFT)
		{
			player.dir = LSPACE;
			if (enemies.enemy2x <= player.x && player.x - 4 <= enemies.enemy2x)
			{
				enemies.enemy2hp -= player.atk;

				if (enemies.enemy2hp <= 0)
				{
					enemies.enemy2act = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemycount)
					{
						enemies.Respawn();

					}
					else if (DataManager::Get()->killCount == Enemycount)
					{
						enemies.enemy2act = false;
					}
				}
			}

		}

		else if (player.dir == RIGHT)
		{
			player.dir = RSPACE;
			if (enemies.enemy2x >= player.x && player.x + 4 >= enemies.enemy2x)
			{
				enemies.enemy2hp -= player.atk;

				if (enemies.enemy2hp <= 0)
				{
					enemies.enemy2act = false;
					player.playermoney += 100;
					DataManager::Get()->killCount++;
					if (DataManager::Get()->killCount < Enemycount)
					{
						enemies.Respawn();

					}
					else if (DataManager::Get()->killCount == Enemycount)
					{
						enemies.enemy2act = false;
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
	if (!enemies.enemy2act)
	{
		return;
	}
	if (player.x == enemies.enemy2x)
	{
		player.hp -= enemies.enemy2dmg;
		if (player.hp <= 0)
		{
			player.dir = DIE;
			enemies.enemy2act = false;

			return;
		}
	}

}

void BattleManager::NextBoss()
{
}

void BattleManager::PlayerBoss()
{
}
