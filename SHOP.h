#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Shop : public Scene
{
private:
	int x = 10;
	int y = 20;
	string shape[12];
public:
	 virtual void Init() override;
	 virtual void Update() override;
	 void Rendershop();
};

