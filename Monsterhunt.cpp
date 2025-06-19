#include "SceneManager.h"
#include "DoubleBuffer.h"

int main()
{
	//버퍼 출력
	
	DoubleBuffer::Get()->InitBuffer();
	SceneManager::Get()->Setscene(LOGO);
	
	while (true)
	{
		system("cls");
		SceneManager::Get()->Init();
		SceneManager::Get()->Update();
		DoubleBuffer::Get()->FlipBuffer();
		DoubleBuffer::Get()->ClearBuffer();

		Sleep(100);
	}

	DoubleBuffer::Get()->CloseBuffer();
	return 0;
}

