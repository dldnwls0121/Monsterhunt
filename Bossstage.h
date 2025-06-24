#pragma once
#include "Scene.h"
class Bossstage : public Scene
{
public:
	virtual void Init() override;
	virtual void Progress() override;
	void Render() override;
};

