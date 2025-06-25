#pragma once
#include "DoubleBuffer.h"
#include "Enemy.h"
#include "Map.h"

enum Dir
{
	LEFT,
	RIGHT,
	LSPACE,
	RSPACE,
	DIE,

};



class PLAYER
{
private:
	
	int atk = 10;
	int def = 5;
	bool fall = false;
	string shape[5][4];
	const float G = 9.81f;
	const float Vo = 11.f;
public:

	int hp = 50;
	Dir dir = LEFT;
	int x = 25;
	int y = 28;
	int playermoney = 500;
	Map* map = new Map;
	void init();
	void Playermove(Enemy & enemy);
	void Renderplayer();
};

