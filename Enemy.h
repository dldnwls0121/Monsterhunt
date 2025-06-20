#pragma once
#include "DoubleBuffer.h"


class Enemy
{
private:
	string shape[4];
public:
	int enemyx = 35;
	int enemyy = 28;
	int enemydmg = 5;
	bool enemyact = true;
	int enemyhp = 10;
	void init();
	void Enemymove(int x);
	void Enemyprt();
};

