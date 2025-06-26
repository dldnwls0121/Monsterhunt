#include "LOGO.h"
#include "DoubleBuffer.h"
#include "Color.h"
#include "PLAYER.h"
#include "Enemy.h"
#include "Datamanager.h"

void Logo::Init() 
{
	playershape[0][0] = "          ";
	playershape[0][1] = " ○    ";
	playershape[0][2] = "(ㅣo---  ";
	playershape[0][3] = " ㅅ      ";

	playershape[1][0] = "             ";
	playershape[1][1] = "    ○    ";
	playershape[1][2] = "   (ㅣ o---  ";
	playershape[1][3] = "    ㅅ      ";

	playershape[2][0] = "                 ";
	playershape[2][1] = "        ○    ";
	playershape[2][2] = "       (ㅣ o-->  ";
	playershape[2][3] = "        ㅅ      ";

	playershape[3][0] = "                     ";
	playershape[3][1] = "            ○    ";
	playershape[3][2] = "           (ㅣ o-->>  ";
	playershape[3][3] = "            ㅅ      ";


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

	DataManager::Get()->SetPlayer();
}

//int currentSpaceState2 = GetAsyncKeyState(VK_RETURN) & 0x8000;
void Logo::Progress()
{
	
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SceneManager::Get()->Setscene(MENU);
	}
	
}


int playerani= 0; 
int enemyani=0; 

void Logo::Render()
{
	playerani++;//속도 조절용

	if (playerani >= 10)
	{
		planiindex++;//다음 장면 전환용
		if (planiindex >= 4)
		{
			planiindex = 0;
		}
		playerani = 0;
	}

	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(playerx, playery+i, playershape[planiindex][i], WHITE);
	}


	enemyani++;

	if (enemyani >= 10)
	{
		enaniindex++;
		if (enaniindex >=5)
		{
			enaniindex = 0;

		}
		enemyani = 0;
	}
	
	for (int i = 0; i < 8; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(enemyx, enemyy + i, enemyshape[enaniindex][i], RED);
	}


	DoubleBuffer::Get()->WriteBuffer(12, 23, "==============================", WHITE);
	DoubleBuffer::Get()->WriteBuffer(17, 25, "PRESS ENTER", WHITE);

}







