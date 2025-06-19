#pragma once
#include "DoubleBuffer.h"
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
	int x;
	int y;
	int hp;
	int atk;
	int def;
	Dir dir;
	string shape[5][4];
public:
	void init();
	void Progressstage();
	void Renderstage();
};

