#include "Stage2.h"
#include <iostream>
#include "Color.h"
void Stage2::Init()
{
	shape[0] = "   �Ѥ�   ";
	shape[1] = "�ѤӡۤӤ�";
	shape[2] = "   �Ѥ�   ";
}

void Stage2::Progress()
{
	
}

void Stage2::Render()
{
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::Get()->WriteBuffer(x, y + i, shape[i], RED);
	}
}
