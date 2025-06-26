#include "PLAYER.h"
#include "Color.h"
#include <Windows.h>
#include "Datamanager.h"

void PLAYER::init()
{

	shape[0][0] = "          ";
	shape[0][1] = "    ○   ";
	shape[0][2] = "---oㅣ)   ";
	shape[0][3] = "    ㅅ      ";

	shape[1][0] = "          ";
	shape[1][1] = " ○    ";
	shape[1][2] = "(ㅣo---  ";
	shape[1][3] = " ㅅ      ";

	shape[2][0] = "          ";
	shape[2][1] = "     ○   ";
	shape[2][2] = "<<--oㅣ)   ";
	shape[2][3] = "     ㅅ      ";

	shape[3][0] = "          ";
	shape[3][1] = " ○    ";
	shape[3][2] = "(ㅣ -->>  ";
	shape[3][3] = " ㅅ      ";

	shape[4][0] = "        ";
	shape[4][1] = "        ";
	shape[4][2] = "        ";
	shape[4][3] = "○+ㅡ<   ";


}

void PLAYER::Playermove(std::vector<Enemy>& enemies)
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

		if (GetAsyncKeyState(VK_UP) && !fall)
		{
			fall = true;
			t = 0.f;
			h = y;
		}
		if (fall)
		{
			t += 0.3f;		//20 초기 플레이어 위치값
			y = (int)(h - (Vo * t) + (0.5f * G * t * t));


			//20 초기 플레이어 위치값
			if (y >= h)
			{
				y = h;
				fall = false;
			}
		}
	
		if (GetAsyncKeyState(VK_SPACE))
		{
			for (auto& enemy : enemies)
			{
				if (enemy.enemyact == false)
				{
					continue;
				}
				if (dir == LEFT)
				{
					dir = LSPACE;
					if (enemy.enemyx <= x && x - 4 <= enemy.enemyx)
					{
						enemy.enemyhp -= atk;
						//Utilty::setpos(20, 20);
						//cout << atk << "피해를 입혔습니다" << endl;
						if (enemy.enemyact == true)
						{
							if (enemy.enemyhp <= 0)
							{
								playermoney += 100;
								enemy.enemyact = false;

							}
						}

					}

				}
				else if (dir == RIGHT)
				{
					dir = RSPACE;
					if (enemy.enemyx >= x && x + 4 >= enemy.enemyx)
					{
						enemy.enemyhp -= atk;

						if (enemy.enemyact == true)
						{
							if (enemy.enemyhp <= 0)
							{
								playermoney += 100;
								enemy.enemyact = false;

							}

						}
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
		std::vector<Enemy>& enemies = DataManager::Get()->currentenemise;
			
		
		for (Enemy& enemy : enemies)
		{
			enemy.Enemymove(x, y);
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
	char player_Gold[10];
	_itoa_s(playermoney, player_Gold, 10);
	map->Mapinit();

	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[dir][i], WHITE);
	}

	DoubleBuffer::Get()->WriteBuffer(0, 0, "체력 : ",WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 0, player_hp, RED);
	DoubleBuffer::Get()->WriteBuffer(0, 2, "공격력 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 2, player_atk, WHITE);
	DoubleBuffer::Get()->WriteBuffer(0, 4, "방어력 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 4, player_def, WHITE);
	DoubleBuffer::Get()->WriteBuffer(0, 6, "소지금 : ", WHITE);
	DoubleBuffer::Get()->WriteBuffer(4, 6, player_Gold, YELLOW);
	DoubleBuffer::Get()->WriteBuffer(20, 0, " /8 처치 수", YELLOW);
}

void PLAYER::PlayerDamage(const std::vector<Enemy>& enemies)
{
	for (const auto& enemy : enemies)
	{
		if (!enemy.enemyact) continue;

		// x 좌표가 충돌 범위 내에 있는지 체크 (예: +-4)
		if (x >= enemy.enemyx - 4 && x <= enemy.enemyx + 4)
		{
			hp -= enemy.enemydmg;
			if (hp <= 0)
			{
				dir = DIE;
				break; 
			}
		}
	}
}