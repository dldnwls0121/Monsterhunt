#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "PLAYER.h"
#include <conio.h>
int main()
{
	//버퍼 출력
	
	DoubleBuffer::Get()->InitBuffer();
	SceneManager::Get()->Setscene(LOGO);
	
	while (true)
	{
	
		if (_kbhit)
		{
			SceneManager::Get()->Init();
			SceneManager::Get()->Render();
			SceneManager::Get()->Progress();
			DoubleBuffer::Get()->FlipBuffer();
			DoubleBuffer::Get()->ClearBuffer();
	
		}

		Sleep(50);
	}

	DoubleBuffer::Get()->CloseBuffer();
	return 0;
}

