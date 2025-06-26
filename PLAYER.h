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
#pragma region 점프 구현 변수
	int h;
	float t;
	const float G = 9.81f;
	const float Vo = 11.f;
#pragma endregion

public:
	int hp = 50;
	int atk = 10;
	int def = 5;
	Dir dir = LEFT;
	int x = 25;
	int y = 28;
	int playermoney = 500;
	Map* map = new Map;
	void init();
	void Playermove();
	void Renderplayer();
	void PlayerDamage(Enemy& enemies);
};

