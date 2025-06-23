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

};