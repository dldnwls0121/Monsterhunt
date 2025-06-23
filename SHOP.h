#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "PLAYER.h"
#include "STAGE.h"

class Shop : public Scene
{
private:
	int x = 10;
	int y = 5;
	int arrowx = 14;
	int arrowy = 20;
	int Hppotion = 100;
	int Strpotion = 300;
	int Defpotion = 200;
	string shape[12];
	string arrow = "->";
	PLAYER player;
public:
	 virtual void Init() override;
	 virtual void Progress() override;
	 void Render() override;
};

