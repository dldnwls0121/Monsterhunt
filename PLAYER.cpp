#include "PLAYER.h"
#include "Color.h"
#include <conio.h>
#include <Windows.h>


void PLAYER::init()
{




	shape[0][0] = "          ";
	shape[0][1] = "     ∞   ";
	shape[0][2] = "天天o太)   ";
	shape[0][3] = "     今      ";

	shape[1][0] = "          ";
	shape[1][1] = " ∞    ";
	shape[1][2] = "(太o天天  ";
	shape[1][3] = " 今      ";

	shape[2][0] = "          ";
	shape[2][1] = "      ∞   ";
	shape[2][2] = "<<天o 太)   ";
	shape[2][3] = "      今      ";

	shape[3][0] = "          ";
	shape[3][1] = " ∞    ";
	shape[3][2] = "(太 o天>>  ";
	shape[3][3] = " 今      ";

	shape[4][0] = "        ";
	shape[4][1] = "        ";
	shape[4][2] = "        ";
	shape[4][3] = "∞+天<   ";
}

void PLAYER::Playermove(Enemy& enemy)
{
	
		if (GetAsyncKeyState(VK_LEFT))
		{
			dir = LEFT;
			x--;
			if (x <= 0)
			{
				x++;
			}
	
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			dir = RIGHT;
			x++;
			if (x >= 40)
			{
				x--;
			}
			
		
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (dir == LEFT)
			{
		
				dir = LSPACE;
				enemy.enemyhp -= atk;
				if (enemy.enemyhp == 0)
				{
					enemy.enemyact = false;
				}
			
			}
			else if (dir == RIGHT)
			{
				dir = RSPACE;
				enemy.enemyhp -= atk;
			}
			
		
		}
		else
		{
			if (dir == RSPACE)
			{
				dir = RIGHT;
			}
			if (dir == LSPACE)
			{
				dir = LEFT;
			}
		}
		
		enemy.Enemymove(x);
	
}

void PLAYER::playerhurt(Enemy& enemy)
{
	if (enemy.enemyact == true)
	{
		if (x == enemy.enemyx)
		{
			hp -= enemy.enemydmg;
			if (hp == 0)
			{
				enemy.enemyact = false;
				dir = DIE;
			}
		}
	}

}

void PLAYER::Renderplayer()
{
	char player_hp[10];
	_itoa_s(hp, player_hp, 10);
	map->Mapinit();
	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[dir][i], WHITE);
	}
	DoubleBuffer::Get()->WriteBuffer(0, 0, "羹溘 : ",WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 0, player_hp, RED);

}
