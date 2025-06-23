#pragma once
#include "PLAYER.h"


class DataManager
{
private:
	static DataManager* instance;
	
public:
	static DataManager* Get()
	{
		if (instance == nullptr)
		{
			instance = new DataManager;
		}

		return instance;
	}

	PLAYER* currentplayer = nullptr;
};

