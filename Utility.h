#pragma once
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <random>

class Utilty
{
public:
	static void setpos(int x, int y)
	{
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static int GetRandomInt(int max)
	{
		static std::random_device rd; // �õ� ������
		static std::mt19937 gen(rd()); // Mersenne Twister ����
		std::uniform_int_distribution<> dist(1, max); // 1���� max������ ������ ���� ����
		return dist(gen); // ��
	}
};