#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <windows.h>
#include <conio.h>
#include "BoardManager.h"

class InputHandler {
public:
	static void getInputs();

private:
	static void dKeyPressed();
	static void sKeyPressed();
	static void aKeyPressed();
	static void spaceKeyPressed();

};

#endif