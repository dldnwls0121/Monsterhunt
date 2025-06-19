#include "SHOP.h"
void Shop::Init()
{
	cout << "shop" << endl;
}

void Shop::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(STAGE);
	}
}