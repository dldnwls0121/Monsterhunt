#pragma once
#include "PLAYER.h"
#include "Enemy.h"

class DataManager
{
private:
	static DataManager* instance;
	
public:
	PLAYER* currentplayer = nullptr;
	Enemy* currentenemy = nullptr;
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
		currentenemy = new Enemy;
	}

	void ReleasePlayer()
	{

	}
};

