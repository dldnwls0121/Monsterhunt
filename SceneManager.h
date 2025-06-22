#pragma once
#include "Scene.h"
#include "DoubleBuffer.h"
#include <iostream>
#include <Windows.h>

using namespace std;

enum SCENE_ID
{
	LOGO,
	MENU,
	SHOP,
	STAGE,

};

class SceneManager
{
private:
	static SceneManager* instance;
	 Scene * currentscene= nullptr;
public:
	static SceneManager * Get()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager;
		}
		return instance;
	}


public:
	void Setscene(const SCENE_ID& id);
	void Init();
	void Update();
	void Render();
};

