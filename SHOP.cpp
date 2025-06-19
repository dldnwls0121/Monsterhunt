#include "SHOP.h"
#include "Color.h"
void Shop::Init()
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "shop", 1);
}

void Shop::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(STAGE);
	}
}