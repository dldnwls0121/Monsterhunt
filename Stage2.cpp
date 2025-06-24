#include "Stage2.h"
#include <iostream>
#include "Color.h"
void Stage2::Init()
{
	shape[0] = "   天天   ";
	shape[1] = "天太∞太天";
	shape[2] = "   天天   ";
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
