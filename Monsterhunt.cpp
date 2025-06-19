#include "SceneManager.h"
#include "DoubleBuffer.h"
int main()
{
	//버퍼 출력
	SceneManager::Get()->Setscene(LOGO);
	DoubleBuffer::Get()->InitBuffer();
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

