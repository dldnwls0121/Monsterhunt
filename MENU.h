#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Menu : public Scene
{
	int logoMenux = 1;
	int logoMenuy = 10;
	int arrowx = 13;
	int arrowy = 25;
	int Prev_arrowy = 30;
	string logoMenushape[6];
	string arrow= "->";
	string Prev_arrow = "   ";
public:
	 virtual void Init() override;
	 virtual void Progress() override;
	 void Render() override;
	 virtual ~Menu() override;
};

