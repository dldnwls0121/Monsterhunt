#pragma once
#include <iostream>
#include <Windows.h>

using namespace std; // ���� ���ۿ� ��� ����

#define BufferWidth 80	// ���� ���� ũ��
#define BufferHeight 40 // ���� ���� ũ��


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

