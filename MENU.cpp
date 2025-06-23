#include "MENU.h"
#include "Color.h"
void Menu::Init() 
{
	logoMenushape[0] = "#  #                   #                     #  #               #   ";
	logoMenushape[1] = "####                   #                     #  #               #";
	logoMenushape[2] = "####   ##   ###   ### ###    ##   ###        ####  #  #  ###   ###    ##   ###";
	logoMenushape[3] = "#  #  #  #  #  # ##    #    # ##  #  #       #  #  #  #  #  #   #    # ##  #  #";
	logoMenushape[4] = "#  #  #  #  #  #   ##  #    ##    #          #  #  #  #  #  #   #    ##    #";
	logoMenushape[5] = "#  #   ##   #  # ###    ##   ##   #          #  #   ###  #  #    ##   ##   #";

}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_UP))
	{
		arrowy -= 5;
		if (arrowy <= 25)
		{
			arrowy = 25;
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		arrowy += 5;
		if (arrowy >= 30)
		{
			arrowy = 30;
		}
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (arrowy == 25)
		{
			SceneManager::Get()->Setscene(STAGE);
		}
		if (arrowy == 30)
		{
			SceneManager::Get()->Setscene(SHOP);
		}
	}

}

void Menu::Render()
{
	for (int i = 0; i < 6; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(logoMenux, logoMenuy+i,logoMenushape[i],WHITE);
	}

	DoubleBuffer::Get()->WriteBuffer(arrowx, arrowy, arrow, WHITE);
	DoubleBuffer::Get()->WriteBuffer(18, 25, "GAMEPLAY", WHITE);
	DoubleBuffer::Get()->WriteBuffer(18, 30, "SHOP", WHITE);
}
