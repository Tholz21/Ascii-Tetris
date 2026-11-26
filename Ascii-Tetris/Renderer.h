#ifndef RENDERER_H
#define RENDERER_H
#include "BoardManager.h"
#include "ConsoleUtils.h"
#include <string>
#include <iostream>

using namespace std;

class Renderer {
public:
	static void renderGame();
	static void renderStartScreen();
	static void renderGameTitle();
	void renderEndScreen(int score);
};
#endif