#include "STAGE.h"
#include "Color.h"
#include "Datamanager.h"




void Stage::Init()
{
	DataManager::Get()->currentplayer->init();

}



void Stage::Progress()
{	
	DataManager::Get()->currentplayer->Playermove(DataManager::Get()->currentenemise);
	DataManager::Get()->currentplayer->PlayerDamage(DataManager::Get()->currentenemise);
}


void Stage::Render()
{
	
	DataManager::Get()->currentplayer->Renderplayer();
	for (Enemy& enemy : DataManager::Get()->currentenemise)
	{
		if (enemy.enemyact)  // 살아있는 적만
			enemy.RenderEnemy();
	}
}
