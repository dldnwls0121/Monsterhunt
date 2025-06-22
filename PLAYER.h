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
	int hp = 50;
	int atk = 10;
	int def = 5;
	Dir dir = LEFT;
	string shape[5][4];
public:
	int x = 25;
	int y = 28;
	//PLAYER(int hp, int atk, int def) : hp(hp), atk(atk), def(def) {}
	Map* map = new Map;
	void init();
	void Playermove(Enemy & enemy);
	void playerhurt(Enemy& enemy);
	void Renderplayer();
};

