#pragma once
#include "DoubleBuffer.h"

#define Boss_attack 5

class Boss
{
private:
	string shape[3][8];
	string Dieshape[8];

	int Speed = 0;
	int aniindex = 0;

public:
	int bossattackcount = 0;
	int bossx = 27;
	int bossy = 24;
	int bossdmg = 10;
	bool bossact = true;
	bool boss_attack = true;
	int bosshp = 100;


	int attack_x[Boss_attack];
	int attack_y[Boss_attack];
	bool attack_active[Boss_attack];
	string attack_shape[Boss_attack];

	
	void init();

	void RenderBoss();

};

