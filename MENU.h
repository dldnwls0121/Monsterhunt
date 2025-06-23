#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Menu : public Scene
{
	int logoMenux = 0;
	int logoMenuy = 10;
	int arrowx = 13;
	int arrowy = 25;
	string logoMenushape[6];
	string arrow= "->";

public:
	 virtual void Init() override;
	 virtual void Progress() override;
	 void Render() override;
};

