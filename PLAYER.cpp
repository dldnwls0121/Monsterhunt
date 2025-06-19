#include "PLAYER.h"
#include "Color.h"
void PLAYER::init()
{
	x = 25;
	y = 28;
	hp = 50;
	atk = 10;
	def = 5;
	dir = LEFT;
	shape[0][0] = "          ";
	shape[0][1] = " ∞    ";
	shape[0][2] = "(太o天天  ";
	shape[0][3] = " 今      ";

	shape[1][0] = "          ";
	shape[1][1] = "     ∞   ";
	shape[1][2] = "天天o太)   ";
	shape[1][3] = "     今      ";

	shape[2][0] = "          ";
	shape[2][1] = "      ∞   ";
	shape[2][2] = "<<天o 太)   ";
	shape[2][3] = "      今      ";

	shape[3][0] = "          ";
	shape[3][1] = " ∞    ";
	shape[3][2] = "(太 o天>>  ";
	shape[3][3] = " 今      ";

	shape[4][0] = "          ";
	shape[4][1] = "        ";
	shape[4][2] = "         ";
	shape[4][3] = "∞+天<      ";
}

void PLAYER::Progressstage()
{

}

void PLAYER::Renderstage()
{
	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[dir][i], WHITE);
	}
}
