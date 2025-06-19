#include "LOGO.h"


void Logo::Init() 
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "logo", 0);
}

void Logo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(MENU);
	}

}