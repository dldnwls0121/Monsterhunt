#pragma once
#include "PLAYER.h"
#include "Enemy.h"

class DataManager
{
private:
	static DataManager* instance;
	
public:
	PLAYER* currentplayer = nullptr;
	std::vector<Enemy> currentenemise;
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
		currentenemise.clear();

		for (int i = 0; i < Enemycount; i++)
		{
		
			Enemy enemies;
			enemies.init();

			currentenemise.push_back(enemies);

		}
	}

	void ReleasePlayer()
	{

	}
};

