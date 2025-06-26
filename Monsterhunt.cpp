#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "PLAYER.h"
#include <conio.h>
#include <time.h>
int main()
{
	//버퍼 출력
	srand((unsigned int)time(NULL));
	DoubleBuffer::Get()->InitBuffer();
	SceneManager::Get()->Setscene(LOGO);
	

	while (true)
	{	
		SceneManager::Get()->Init();
		SceneManager::Get()->Progress();
		SceneManager::Get()->Render();
		DoubleBuffer::Get()->FlipBuffer();
		DoubleBuffer::Get()->ClearBuffer();
		
		 Sleep(50);
	}

	DoubleBuffer::Get()->CloseBuffer();
	return 0;
}

