#include "MENU.h"
void Menu::Init() 
{
	cout << "Menu" << endl;
}

void Menu::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(SHOP);
	}
}