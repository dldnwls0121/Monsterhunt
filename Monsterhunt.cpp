#include "SceneManager.h"
#include "DoubleBuffer.h"
#include "PLAYER.h"
int main()
{
	//버퍼 출력
	
	DoubleBuffer::Get()->InitBuffer();
	SceneManager::Get()->Setscene(LOGO);

	while (true)
	{
		
		SceneManager::Get()->Init();
		//SceneManager::Get()->Update();
		DoubleBuffer::Get()->FlipBuffer();
		DoubleBuffer::Get()->ClearBuffer();

		Sleep(30);
	}

	DoubleBuffer::Get()->CloseBuffer();
	return 0;
}

