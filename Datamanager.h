#pragma once
#include "PLAYER.h"
#include "Enemy.h"
#include "Color.h"
#include "SceneManager.h"
class DataManager
{
private:
	static DataManager* instance;

public:
	PLAYER* currentplayer = nullptr;
	Enemy* currentenemy = nullptr;
	int killCount = 0;
	static DataManager* Get()
	{
		if (instance == nullptr)
		{
			instance = new DataManager;
		}

		return instance;
	}

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


	void ReleasePlayer()
	{

	}
};

