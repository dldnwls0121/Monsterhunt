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
		// 다른 클래스 render 정의하기
		SceneManager::Get()->Init();
		SceneManager::Get()->Render();
		//SceneManager::Get()->Update();
		DoubleBuffer::Get()->FlipBuffer();
		DoubleBuffer::Get()->ClearBuffer();

		Sleep(10);
	}

	DoubleBuffer::Get()->CloseBuffer();
	return 0;
}

