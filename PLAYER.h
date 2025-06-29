#pragma once
#include "DoubleBuffer.h"
#include "Enemy.h"
#include "Map.h"
#include <vector>
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
	bool fall = false;
	string shape[5][4];
#pragma region 점프 구현 
	int h;
	float t;
	const float G = 9.81f;
	const float Vo = 11.f;
#pragma endregion

public:
	int hp = 50;
	int atk = 10;
	int def = 5;
	int Hppotion = 0;
	int Atkpotion = 0;
	int Defpotion = 0;
	Dir dir = LEFT;
	int x = 20;
	int y = 28;
	int playermoney = 500;
	Map* map = new Map;
	void init();
	void Playermove();
	void Renderplayer();
	void PlayerDamage();
	void DrinkPotion();
};

