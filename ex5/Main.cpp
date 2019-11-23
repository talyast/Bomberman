
#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib")
#pragma comment ( lib , "sfml-system-d.lib")
#pragma comment ( lib , "sfml-window-d.lib")
#pragma comment ( lib , "sfml-graphics-d.lib")
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib")
#pragma comment ( lib , "sfml-system.lib")
#pragma comment ( lib , "sfml-window.lib")
#pragma comment ( lib , "sfml-graphics.lib")
#else
#error "Unrecognize configuration!"
#endif

#include <iostream>
#include <fstream>
#include "GameController.h"
#include <cstdlib>

int main()
{
	srand((unsigned)time(nullptr));

	GameController game;

	game.run();

	return EXIT_SUCCESS;
}