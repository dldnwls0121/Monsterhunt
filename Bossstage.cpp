#include "Bossstage.h"
#include "Datamanager.h"
#include "BattleManager.h"

void Bossstage::Init()
{
	DataManager::Get()->SetBoss();
	DataManager::Get()->currentboss->init();
	DataManager::Get()->currentplayer->init();


}

void Bossstage::Progress()
{
	DataManager::Get()->currentplayer->Playermove();
	DataManager::Get()->currentboss->Bossattack();
	BattleManager::Get()->PlayerBoss();
}

void Bossstage::Render()
{
	DataManager::Get()->currentplayer->Renderplayer();
	DataManager::Get()->currentboss->RenderBoss();
	BattleManager::Get()->BossClear();
	BattleManager::Get()->BossPlayerDie();
}
