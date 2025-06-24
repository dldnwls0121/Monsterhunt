#pragma once
#include "Scene.h"
#include "SceneManager.h"
class Stage2 :public Scene
{
private:
	int hp;
	int x = 29;
	int y = 25;
	string shape[3];
public:
	virtual void Init() override;
	virtual void Progress() override;
	void Render() override;
};

