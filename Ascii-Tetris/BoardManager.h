#include <windows.h>
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include <chrono>
#include "GameManager.h"


using namespace std::chrono;

class BoardManager {
public:
	static int pieces[7][5][5];
	static int currentPiece[5][5];
	static int rotationContainer[5][5];

	static COORD piecePosition;
	static COORD pieceStartingCoords;

	// Board dimensions (add 2 more for board walls)
	static constexpr int boardWidth = 12;
	static constexpr int boardHeight = 22;

	static int gameboard[boardHeight][boardWidth];

	enum cellState {
		empty = 0,
		piece = 1,
		staticPiece = 2,
		wall = 3
  };

	static void instantiateBoard();
	static void randomizeCurrentPiece();
	static bool checkValidMove(COORD checkOffset);
	static bool movePieceIfValid(COORD direction);
	static void rotatePiece();
	static void updateGameBoard(bool collided);
	static void checkAndClearFullLine();
	static bool isGameOver();
	static bool createPiece();
	static void clearBoard();

};

#endif
