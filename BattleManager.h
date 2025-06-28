#pragma once
#include "PLAYER.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Datamanager.h"

#define Enemycount 8
#define Enemy2count 5

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
	void Nextstage2();
	void Playerstage2();
	void NextBoss();
	void PlayerBoss();
	void Stage1PlayerDie();
	void Stage2PlayerDie();
	void BossPlayerDie();
	void BossClear();
};

