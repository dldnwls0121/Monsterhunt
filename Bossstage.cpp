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
	BattleManager::Get()->PlayerBoss();
	DataManager::Get()->currentplayer->DrinkPotion();

}

void Bossstage::Render()
{
	DataManager::Get()->currentplayer->Renderplayer();
	DataManager::Get()->currentboss->RenderBoss();
	BattleManager::Get()->BossClear();
	BattleManager::Get()->BossPlayerDie();
}
