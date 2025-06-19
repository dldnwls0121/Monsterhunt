#pragma once
#include <iostream>
#include <Windows.h>

using namespace std; // 더블 버퍼용 헤더 파일

#define BufferWidth 80	// 가로 버퍼 크기
#define BufferHeight 40 // 세로 버퍼 크기


class DoubleBuffer
{
private:
	static DoubleBuffer* instance;
	HANDLE hBuffer[2];	
	int screenIndex;
public:
	static DoubleBuffer* Get()
	{
		if (instance == nullptr)
		{
			instance = new DoubleBuffer;
		}
		return instance;
	}

	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x, int y, string shape, int color);
	void CloseBuffer();
};

