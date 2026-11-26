#include <windows.h>
#include "InputHandler.h"

void InputHandler::getInputs(){
	if (_kbhit()) {
				char key = _getch();
				
				switch (key) {
					case 'd':
						dKeyPressed();
						break;
					case 'a':
						aKeyPressed();
						break;
					case 'w':
						spaceKeyPressed();
						break;
					default:
						break;
				}
			}
	/*if (GetAsyncKeyState('d') & 0X8000) {
		dKeyPressed();
	}
	else if (GetAsyncKeyState('s') & 0X8000) {
		sKeyPressed();
	}
	else if (GetAsyncKeyState('a') & 0X8000){
		aKeyPressed();
	}
	else if(GetAsyncKeyState(VK_SPACE) & 0X8000) {
		spaceKeyPressed();
	}*/
}

void InputHandler::dKeyPressed(){
    if (BoardManager::movePieceIfValid(COORD{ 1, 0 })) {
		BoardManager::updateGameBoard(false);
	}
}

void InputHandler::sKeyPressed(){
}

void InputHandler::aKeyPressed(){
  if (BoardManager::movePieceIfValid(COORD{ -1, 0 })) {
		BoardManager::updateGameBoard(false);
	}
}

void InputHandler::spaceKeyPressed(){
	BoardManager::rotatePiece();
	BoardManager::updateGameBoard(false);
}
