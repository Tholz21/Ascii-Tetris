#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "InputHandler.h"
#include "Renderer.h"
#include "ConsoleUtils.h"
#include "TimeUtils.h"
#include "InputHandler.h"

class GameManager {
public:
	static int score;

	static bool startScreen();
	static int startGame();
	static void endScreen(int score);
};

#endif