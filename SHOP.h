#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Datamanager.h"
#include "STAGE.h"

class Shop : public Scene
{
private:
	int x = 10;
	int y = 5;
	int arrowx = 14;
	int arrowy = 20;
	int Prev_arrowy = 25;
	int Hppotion = 100;
	int Strpotion = 300;
	int Defpotion = 200;
	string shape[12];
	string arrow = "->";
	string Prev_arrow = "  ";

public:

	 void Init() override;
	 void Progress() override;
	 void Render() override;
	 virtual ~Shop() override;
};

