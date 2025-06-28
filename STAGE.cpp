#include "STAGE.h"
#include "Datamanager.h"
#include "BattleManager.h"
void Stage::Init()
{
	DataManager::Get()->SetEnemy();
	DataManager::Get()->currentplayer->init();
	DataManager::Get()->currentenemy->init();
}
void Stage::Progress()
{	

	DataManager::Get()->currentplayer->Playermove();
	BattleManager::Get()->Playerstage1();
	DataManager::Get()->currentenemy->Enemymove(DataManager::Get()->currentplayer->x, DataManager::Get()->currentplayer->y);

}


void Stage::Render()
{
	DataManager::Get()->currentplayer->Renderplayer();
	DataManager::Get()->currentenemy->RenderEnemy();
	BattleManager::Get()->Nextstage2();
	BattleManager::Get()->Stage1PlayerDie();
}
