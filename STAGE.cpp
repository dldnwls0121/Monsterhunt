#include "STAGE.h"
#include "Color.h"
#include "Datamanager.h"




void Stage::Init()
{
	DataManager::Get()->currentplayer->init();
	DataManager::Get()->currentenemy->init();
}



void Stage::Progress()
{	

	DataManager::Get()->currentplayer->Playermove();
	DataManager::Get()->currentplayer->PlayerDamage(*DataManager::Get()->currentenemy);
	DataManager::Get()->currentenemy->Enemymove(DataManager::Get()->currentplayer->x, DataManager::Get()->currentplayer->y);
}


void Stage::Render()
{
	
	DataManager::Get()->currentplayer->Renderplayer();
	DataManager::Get()->currentenemy->RenderEnemy();
}
