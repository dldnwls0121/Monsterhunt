#pragma once
#include "DoubleBuffer.h"

#define Enemycount 8
class Enemy
{
private:
	string shape[4];
	
public:
	int enemyx;
	int enemyy;
	int enemydmg;
	bool enemyact;
	bool Allenemydie;
	int enemyhp;

	Enemy();
	void init();
	void Enemymove(int x,int y);
	void RenderEnemy();
};

