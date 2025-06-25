#pragma once
#include "DoubleBuffer.h"
#include <time.h>
#define Enemycount 8

class Enemy
{
private:
	string shape[4];
public:
	int enemyx = (rand() % 2 == 0) ? 0 : 40;
	int enemyy = 28;
	int enemydmg = 5;
	bool enemyact = true;
	int enemyhp = 10;
	void init();
	void Enemymove(int x);
	void RenderEnemy();
	void EnemyHurt();
};

