#include "PLAYER.h"
#include "Color.h"
#include <Windows.h>
#include "Datamanager.h"
#include "SceneManager.h"
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

void PLAYER::Playermove()
{
	Enemy& enemies = *DataManager::Get()->currentenemy;
	

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
			
			// 적 인원 추가 하고 투명 적 수정
			
					if (dir == LEFT)
					{
						dir = LSPACE;
						if (enemies.enemyx <= x && x - 4 <= enemies.enemyx)
						{
							enemies.enemyhp -= atk;

							if (enemies.enemyhp <= 0)
							{
								for (int i = 0; i < Enemycount; i++)
								{
									enemies.enemyact = false;
									playermoney += 100;
									//if (!enemies.enemyact)
									//{
									//	enemies.Respawn();
									//	
									//	if (enemies.countenemy == Enemycount)
									//	{
									//		enemies.enemyact = false;
									//		break;
									//	}
									//}
								}
							}


						}

					}
					else if (dir == RIGHT)
					{
						dir = RSPACE;
						if (enemies.enemyx >= x && x + 4 >= enemies.enemyx)
						{
							enemies.enemyhp -= atk;

							for (int i = 0; i < Enemycount; i++)
							{
								if (enemies.enemyhp <= 0)
								{

									enemies.enemyact = false;
									playermoney += 100;

									//if (!enemies.enemyact)
									//{
									//	enemies.Respawn();
									//	
									//	if (enemies.countenemy == Enemycount)
									//	{
									//		enemies.enemyact = false;
									//		break;
									//	}
									//}

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

		
		enemies.Enemymove(x, y);

}

void PLAYER::PlayerDamage(Enemy& enemies)
{

		// x 좌표가 충돌 범위 내에 있는지 체크 (예: +-4)
		if (x == enemies.enemyx)
		{
			hp -= enemies.enemydmg;
			if (hp <= 0)
			{
				dir = DIE;
				enemies.enemyact = false;
			
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

	if (DataManager::Get()->killCount == Enemycount)
	{
		DoubleBuffer::Get()->WriteBuffer(10, 10, "모든 몬스터를 처치했습니다! ", YELLOW);
		DoubleBuffer::Get()->WriteBuffer(10, 11, "다음 스테이지로 갈려면 Enter을 눌러주세요!", YELLOW);
		if (GetAsyncKeyState(VK_RETURN))
		{
			SceneManager::Get()->Setscene(STAGE2);
		}
	}

	
}

