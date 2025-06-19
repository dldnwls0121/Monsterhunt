#include "STAGE.h"
#include "Color.h"
void Stage::Init()
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "stage", 1);
}

void Stage::Update()
{
	cout << "  " << endl;
}