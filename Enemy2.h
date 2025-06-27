#pragma once
#include "Color.h"
#include "DoubleBuffer.h"

class Enemy2
{
private:
	int enemy2hp = 20;
	int enemy2x = 29;
	int enemy2y = 25;
	int enemy2dmg = 5;
	bool enemy2act = true;
	string shape[3];
	int Speed = 0;
public:
	void init();
	void Enemymove2(int x, int y);
	void RenderEnemy();
	void Respawn();
};

