#include "Stage2.h"
#include "Datamanager.h"
#include "BattleManager.h"

void Stage2::Init()
{
	DataManager::Get()->SetEnemy2();
	DataManager::Get()->currentplayer->init();
	DataManager::Get()->currentenemy2->init();
}

void Stage2::Progress()
{
	DataManager::Get()->currentplayer->Playermove();
	BattleManager::Get()->Playerstage2();
	DataManager::Get()->currentenemy2->Enemymove2(DataManager::Get()->currentplayer->x, DataManager::Get()->currentplayer->y);
}

void Stage2::Render()
{
	DataManager::Get()->currentplayer->Renderplayer();
	DataManager::Get()->currentenemy2->RenderEnemy();
	BattleManager::Get()->NextBoss();
	BattleManager::Get()->Stage2PlayerDie();
}
