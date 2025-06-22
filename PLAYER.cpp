#include "PLAYER.h"
#include "Color.h"
#include <conio.h>
#include <Windows.h>


void PLAYER::init()
{




	shape[0][0] = "          ";
	shape[0][1] = "     ○   ";
	shape[0][2] = "ㅡㅡoㅣ)   ";
	shape[0][3] = "     ㅅ      ";

	shape[1][0] = "          ";
	shape[1][1] = " ○    ";
	shape[1][2] = "(ㅣoㅡㅡ  ";
	shape[1][3] = " ㅅ      ";

	shape[2][0] = "          ";
	shape[2][1] = "      ○   ";
	shape[2][2] = "<<ㅡo ㅣ)   ";
	shape[2][3] = "      ㅅ      ";

	shape[3][0] = "          ";
	shape[3][1] = " ○    ";
	shape[3][2] = "(ㅣ oㅡ>>  ";
	shape[3][3] = " ㅅ      ";

	shape[4][0] = "        ";
	shape[4][1] = "        ";
	shape[4][2] = "        ";
	shape[4][3] = "○+ㅡ<   ";
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
				if (enemy.enemyhp == true)
				{
					if (enemy.enemyhp == 0)
					{
						enemy.enemyact = false;
					}
				}
		
			
			}
			else if (dir == RIGHT)
			{
				dir = RSPACE;
				enemy.enemyhp -= atk;
				if (enemy.enemyhp == true)
				{
					if (enemy.enemyhp == 0)
					{
						enemy.enemyact = false;
					}
				}
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
	char player_atk[10];
	_itoa_s(atk, player_atk, 10);
	char player_def[10];
	_itoa_s(def, player_def, 10);

	map->Mapinit();

	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[dir][i], WHITE);
	}

	DoubleBuffer::Get()->WriteBuffer(0, 0, "체력 : ",WHITE);
	DoubleBuffer::Get()->WriteBuffer(3, 0, player_hp, RED);
	DoubleBuffer::Get()->WriteBuffer(0, 2, "공격력 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(5, 2, player_atk, WHITE);
	DoubleBuffer::Get()->WriteBuffer(0, 4, "방어력 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(5, 4, player_def, WHITE);

}
