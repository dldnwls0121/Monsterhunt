#include "LOGO.h"
#include "DoubleBuffer.h"
#include "Color.h"
void Logo::Init() 
{
	DoubleBuffer::Get()->WriteBuffer(10, 10, "logo", BLACK);
}

void Logo::Update()
{
	
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::Get()->Setscene(MENU);
	}

}