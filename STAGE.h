#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Stage : public Scene
{
public:
	PLAYER* Player = new PLAYER;

	 void Init() override;
	 void Progress() override;
	 void Render() override;
};	 

