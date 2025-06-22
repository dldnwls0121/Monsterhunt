#include "SHOP.h"
#include "Color.h"
void Shop::Init()
{
	shape[0] = "             ¡á        ¡á";
	shape[1] = "           ¡á¡á¡á    ¡á¡á¡á";
	shape[2] = "           ¡á¡á¡á¡á¡á¡á¡á¡á";
	shape[3] = "       ¡á¡á                ¡á¡á";
	shape[4] = "         ¡á    ¡á     ¡á   ¡á";
	shape[5] = "     ¡á¡á¡á                ¡á¡á¡á";
	shape[6] = "         ¡á     ¢Ø¢Ö¢Ø¢Ö   ¡á";
	shape[7] = "       ¡á¡á                ¡á¡á";
	shape[8] = "           ¡á¡á        ¡á¡á";
	shape[9] = "               ¡á¡á¡á¡á";
	shape[10] = "             ¡á       ¡á";
	shape[11] = "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
}

void Shop::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(STAGE);
	}
}

void Shop::Rendershop()
{
	for (int i = 0; i < 12; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y, shape[i], WHITE);
	}
	
}
