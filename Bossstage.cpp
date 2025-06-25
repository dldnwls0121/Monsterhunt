#include "Bossstage.h"
#include "color.h"
void Bossstage::Init()
{
	shape[0] = "      ����  ���  ����";
	shape[1] = "      ����  ���  ����";
	shape[2] = "      ����  ���  ����";
	shape[3] = "��������������";
	shape[4] = "�������   ��   ����";
	shape[5] = "�����       ��       ��";
	shape[6] = "      ����   ��   ����";
	shape[7] = "      �����������";

}

void Bossstage::Progress()
{
	
}

void Bossstage::Render()
{
	for (int i = 0; i < 8; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[i], RED);
	}
}
