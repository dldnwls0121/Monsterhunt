#include "LOGO.h"
#include "DoubleBuffer.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"


PLAYER* Player = new PLAYER;
Enemy enemy;

void Logo::Init() 
{
	playershape[0][0] = "          ";
	playershape[0][1] = " ○    ";
	playershape[0][2] = "(ㅣoㅡㅡ  ";
	playershape[0][3] = " ㅅ      ";

	playershape[1][0] = "          ";
	playershape[1][1] = " ○    ";
	playershape[1][2] = "(ㅣ oㅡ>>  ";
	playershape[1][3] = " ㅅ      ";


	enemyshape[0][0] = "      ■■■  ■■  ■■■";
	enemyshape[0][1] = "      ■■■  ■■  ■■■";
	enemyshape[0][2] = "      ■■■  ■■  ■■■";
	enemyshape[0][3] = "■■■■■■■■■■■■■";
	enemyshape[0][4] = "■■■■■■        ■■■";
	enemyshape[0][5] = "■■■■       ■       ■";
	enemyshape[0][6] = "      ■■■        ■■■";
	enemyshape[0][7] = "      ■■■■■■■■■■";

	enemyshape[1][0] = "      ■■■  ■■  ■■■";
	enemyshape[1][1] = "      ■■■  ■■  ■■■";
	enemyshape[1][2] = "      ■■■  ■■  ■■■";
	enemyshape[1][3] = "■■■■■■■■■■■■■";
	enemyshape[1][4] = "■■■■■■■■■■■■■";
	enemyshape[1][5] = "■■■■       ■       ■";
	enemyshape[1][6] = "      ■■■■■■■■■■";
	enemyshape[1][7] = "      ■■■■■■■■■■";

	enemyshape[2][0] = "      ■■■  ■■  ■■■";
	enemyshape[2][1] = "      ■■■  ■■  ■■■";
	enemyshape[2][2] = "      ■■■  ■■  ■■■";
	enemyshape[2][3] = "■■■■■■■■■■■■■";
	enemyshape[2][4] = "■■■■■■■■■■■■■";
	enemyshape[2][5] = "■■■■■■■■■■■■■";
	enemyshape[2][6] = "      ■■■■■■■■■■";
	enemyshape[2][7] = "      ■■■■■■■■■■";

	enemyshape[3][0] = "      ■■■  ■■  ■■■";
	enemyshape[3][1] = "      ■■■  ■■  ■■■";
	enemyshape[3][2] = "      ■■■  ■■  ■■■";
	enemyshape[3][3] = "■■■■■■■■■■■■■";
	enemyshape[3][4] = "■■■■■■■■■■■■■";
	enemyshape[3][5] = "■■■■■  ■  l  ■   ■";
	enemyshape[3][6] = "      ■■■■■■■■■■";
	enemyshape[3][7] = "      ■■■■■■■■■■";

	enemyshape[4][0] = "      ■■■  ■■  ■■■";
	enemyshape[4][1] = "      ■■■  ■■  ■■■";
	enemyshape[4][2] = "      ■■■  ■■  ■■■";
	enemyshape[4][3] = "■■■■■■■■■■■■■";
	enemyshape[4][4] = "■■■■■■ ■  ■ ■■■";
	enemyshape[4][5] = "■■■■    ■ l  ■    ■";
	enemyshape[4][6] = "      ■■■ ■  ■ ■■■";
	enemyshape[4][7] = "      ■■■■■■■■■■";


	//Player->init();
	//Player->Playermove(enemy);
	//Player->playerhurt(enemy);
	//Player->Renderplayer();
	//enemy.init();
	//enemy.Enemyprt();
}

void Logo::Update()
{
	
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(MENU);
	}
	
}


int playerani= 0; 
int enemyani=0; 

void Logo::Render()
{
	playerani++;//속도 조절용

	if (playerani >= 4)
	{
		planiindex++;//다음 장면 전환용
		if (planiindex >= 2)
		{
			planiindex = 0;
		}
		playerani = 0;
	}

	for (int i = 0; i < 8; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(playerx, playery, playershape[planiindex][i], WHITE);
	}
}


void Logo::Logoanimation()
{

	
}



void Logo::RenderLogo()
{
	
}
