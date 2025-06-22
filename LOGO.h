#pragma once
#include "Scene.h"
#include "SceneManager.h"

class Logo : public Scene
{
private:
	int playerx = 10;
	int playery = 10 ;
	int enemyx = 20;
	int enemyy = 7;
	int planiindex = 0;
	int enaniindex = 0;
	string playershape[2][4];
	string enemyshape[5][8];
public:
	 virtual void Init() override;
	 virtual void Update() override;
	 void Render() override;
	 void Logoanimation();
	 void RenderLogo();
};

