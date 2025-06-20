#include "SceneManager.h"
#include "LOGO.h"
#include "MENU.h"
#include "SHOP.h"
#include "STAGE.h"
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
	default:
		break;
	}
}

void SceneManager::Init()
{
	currentscene->Init();
}

void SceneManager::Update()
{
	currentscene->Update();

}
