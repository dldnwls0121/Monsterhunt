#include "MENU.h"
#include "Color.h"
void Menu::Init() 
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "menu", 1);
}

void Menu::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(SHOP);
	}
}