#pragma once
#include "PLAYER.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Datamanager.h"

class BattleManager
{
private:
	static BattleManager* instance;
public:
	static BattleManager* Get()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = new BattleManager;
		}
		return instance;
	}

	void Playerstage1();
	void Playerstage2();
	void PlayerBoss();
};

