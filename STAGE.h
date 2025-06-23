#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Stage : public Scene
{
public:


	 void Init() override;
	 void Progress() override;
	 void Render() override;
};	 

