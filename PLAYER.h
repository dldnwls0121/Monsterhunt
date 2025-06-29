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
	int hp ;
	int atk;
	int def;
	int Hppotion ;
	int Atkpotion ;
	int Defpotion ;
	Dir dir ;
	int x ;
	int y ;
	int playermoney ;
	Map* map = new Map;
	void init();
	void Playermove();
	void Renderplayer();
	void PlayerDamage();
	void DrinkPotion();
};

