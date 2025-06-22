#include "SHOP.h"
#include "Color.h"
void Shop::Init()
{
	shape[0] = "             ��        ��";
	shape[1] = "           ����    ����";
	shape[2] = "           ���������";
	shape[3] = "       ���                ���";
	shape[4] = "         ��    ��     ��   ��";
	shape[5] = "     ����                ����";
	shape[6] = "         ��     �آ֢آ�   ��";
	shape[7] = "       ���                ���";
	shape[8] = "           ���        ���";
	shape[9] = "               �����";
	shape[10] = "             ��       ��";
	shape[11] = "�������������������";
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
