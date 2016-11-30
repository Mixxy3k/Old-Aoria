#pragma once
#include "MainLoop.h"
int main()
{
	srand(time(NULL));
	MainLoop Game;
	Game.LoadAllFiles();
	return 0;
}