#include "LOGO.h"
#include "DoubleBuffer.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"


PLAYER* Player = new PLAYER;
Enemy enemy;

void Logo::Init() 
{
	
	Player->init();
	Player->Playermove(enemy);
	Player->playerhurt(enemy);
	Player->Renderplayer();
	enemy.init();
	enemy.Enemyprt();
}

void Logo::Update()
{
	
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(MENU);
	}
	
}