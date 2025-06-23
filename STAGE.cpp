#include "STAGE.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"


Enemy enemy;

void Stage::Init()
{
	Player->init();
	enemy.init();
	
}

void Stage::Progress()
{
	Player->Playermove(enemy);
	Player->playerhurt(enemy);
}

void Stage::Render()
{
	Player->Renderplayer();
	enemy.RenderEnemy();
}
