#include "SceneManager.h"
#include "LOGO.h"
#include "MENU.h"
#include "SHOP.h"
#include "STAGE.h"
#include "Stage2.h"
#include "Bossstage.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::Setscene(const SCENE_ID& id)
{
	if (currentscene != nullptr)
	{
		delete currentscene;
		currentscene = nullptr;
	}
	switch (id)
	{
	case LOGO:
		currentscene = new Logo;
		break;
	case MENU:
		currentscene = new Menu;
		break;
	case SHOP:
		currentscene = new Shop;
		break;
	case STAGE:
		currentscene = new Stage;
		break;
	case STAGE2:
		currentscene = new Stage2;
		break;
	case BOSS:
		currentscene = new Bossstage;
		break;
	default:
		break;
	}
}

void SceneManager::Init()
{
	currentscene->Init();
}

void SceneManager::Progress()
{
	currentscene->Progress();

}

void SceneManager::Render()
{
	currentscene->Render();
}
