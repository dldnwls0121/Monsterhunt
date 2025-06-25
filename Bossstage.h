#pragma once
#include "Scene.h"
#include "SceneManager.h"
#define Bossattack 5

class Bossstage : public Scene
{
private:
	int hp = 50;
	int x = 26;
	int y = 24;
	string shape[8];
	bool bossact = true;
public:
	virtual void Init() override;
	virtual void Progress() override;
	void Render() override;
};

