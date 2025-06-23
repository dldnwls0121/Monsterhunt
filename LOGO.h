#pragma once
#include "Scene.h"
#include "SceneManager.h"

class Logo : public Scene
{
private:
	int playerx = 10;
	int playery = 14 ;
	int enemyx = 20;
	int enemyy = 10;
	int planiindex = 0;
	int enaniindex = 0;
	string playershape[4][4];
	string enemyshape[5][8];
public:
	 virtual void Init() override;
	 virtual void Progress() override;
	 void Render() override;

};

