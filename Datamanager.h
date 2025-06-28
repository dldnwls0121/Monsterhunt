#pragma once
#include "PLAYER.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "SceneManager.h"
class DataManager
{
private:
	static DataManager* instance;

public:
	PLAYER* currentplayer = nullptr;
	Enemy* currentenemy = nullptr;
	Enemy2* currentenemy2 = nullptr;
	Boss* currentboss = nullptr;

	int killCount = 0;

	static DataManager* Get()
	{
		if (instance == nullptr)
		{
			instance = new DataManager;
		}

		return instance;
	}

#pragma region 데이터 할당

	void SetPlayer()
	{
		if (currentplayer == nullptr)
		{

			currentplayer = new PLAYER;
		}
	}

	void SetEnemy()
	{

		if (currentenemy == nullptr)
		{
			currentenemy = new Enemy;
		}

	}

	void SetEnemy2()
	{
		if (currentenemy2 == nullptr)
		{
			currentenemy2 = new Enemy2;
		}
	}

	void SetBoss()
	{
		if (currentboss == nullptr)
		{
			currentboss = new Boss;
		}
	}
#pragma endregion



#pragma region data 해제
	void ReleasePlayer()
	{
		if (currentplayer != nullptr)
		{
			delete currentplayer;
			currentplayer = nullptr;
		}
	}

	void ReleaseEnemy()
	{
		if (currentenemy != nullptr)
		{
			delete currentenemy;
			currentenemy = nullptr;
		}
	}
	void ReleaseEnemy2()
	{
		if (currentenemy2 != nullptr)
		{
			delete currentenemy2;
			currentenemy2 = nullptr;
		}
	}
	void ReleaseBoss()
	{
		if (currentboss != nullptr)
		{
			delete currentboss;
			currentboss = nullptr;
		}
	}
#pragma endregion


};

