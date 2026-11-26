#include "BoardManager.h"

// 3D array containing all tetronimo types
//                       z  y  z
int BoardManager::pieces[7][5][5]{
	{
		//O piece (doesnt rotate)
		{ 2, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//I piece 
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//S Piece
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//Z Piece
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//L Piece
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//J Piece
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	},
	{
		//T Piece
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0 },
	}
};

// Current piece type eg. I, T, O
int BoardManager::currentPiece[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
};

// Array for storing piece midway through rotation
int BoardManager::rotationContainer[5][5] = {
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
};

// Current position of middle cell of piece
COORD BoardManager::piecePosition = { 6, 2 };
COORD BoardManager::pieceStartingCoords = { 6, 2 };


// Gameboard declaration (X and Y flipped)
int BoardManager::gameboard[boardHeight][boardWidth]{};


void BoardManager::instantiateBoard() {
	// Set the roofs of the board to wall
	for (int x = 0; x < boardWidth; x++) {
		gameboard[0][x] = wall;
		gameboard[boardHeight - 1][x] = wall;
	}
	// Set the walls of the board to wall
	for (int y = 0; y < boardHeight; y++) {
		gameboard[y][0] = wall;
		gameboard[y][boardWidth - 1] = wall;
	}
}

void BoardManager::randomizeCurrentPiece() {
	srand(static_cast<unsigned int>(time(0)));
	int randomInt = rand() % 7;
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			currentPiece[y][x] = pieces[randomInt][y][x];
		}
	}
}

bool BoardManager::checkValidMove(COORD checkOffset) {
	bool allCheckedEmpty = 1;
	int pieceOffsetX = 0;
	int pieceOffsetY = 0;
	for (int x = 0; x < 5; ++x) {
		for (int y = 0; y < 5; ++y) {
			if (currentPiece[y][x] == 1) {
				pieceOffsetX = x - 3;
				pieceOffsetY = y - 3;
				auto checkTile = gameboard[pieceOffsetY + piecePosition.Y + checkOffset.Y][pieceOffsetX + piecePosition.X + checkOffset.X];
				if (checkTile == wall || checkTile == staticPiece) {
					allCheckedEmpty = false;
					break;
				}
			}

		}
	}
	return allCheckedEmpty;
}

bool BoardManager::movePieceIfValid(COORD direction) {
	if (checkValidMove(direction)) {
		piecePosition.X = piecePosition.X + direction.X;
		piecePosition.Y = piecePosition.Y + direction.Y;
		return true;
	}
	else {
		return false;
	}
}

void BoardManager::rotatePiece(){
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			rotationContainer[x][4 - y] = currentPiece[y][x];
		}
	}
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			currentPiece[y][x] = rotationContainer[y][x];
		}
	}
}

void BoardManager::updateGameBoard(bool collided)
{
	//Clears board
	for (int y = 0; y < boardHeight; y++) {
		for (int x = 0; x < boardWidth; x++) {
			if (gameboard[y][x] == piece) {
				gameboard[y][x] = empty;
			}
		}
	}

	//Builds piece
	for (int x = 0; x < 5; ++x) {
		for (int y = 0; y < 5; ++y) {
			if (currentPiece[y][x] == 1) {
				COORD offset = {
					static_cast<SHORT>(x - 3),
					static_cast<SHORT>(y - 3)
				};
				if (collided == true) {
					gameboard[offset.Y + piecePosition.Y][offset.X + piecePosition.X] = staticPiece;
				}
				else {
					gameboard[offset.Y + piecePosition.Y][offset.X + piecePosition.X] = piece;

				}
			}
		};

	}
	//fullLine(gameManager);
}

void BoardManager::checkAndClearFullLine() {
	for (int y = 1; y < boardHeight - 1; ++y) {
		bool full = true;

		for (int x = 1; x < boardWidth - 1; ++x) {
			if (gameboard[y][x] != staticPiece) {
				full = false;
				break;
			}
		}

		if (full) {
			GameManager::score = GameManager::score + 10;
			for (int x = 1; x < boardWidth - 1; ++x) {
				gameboard[y][x] = 0;
			}
			for (int moveY = y - 1; moveY > 0; moveY--) {
				for (int x = 1; x < boardWidth - 1; ++x) {
					if (gameboard[moveY][x] == staticPiece) {
						gameboard[moveY][x] = empty;
						gameboard[moveY + 1][x] = staticPiece;
					}
				}
			}
		}
	}
}

bool BoardManager::isGameOver() {
	if (gameboard[pieceStartingCoords.Y][pieceStartingCoords.X] == staticPiece) {
		return true;
	}
	else {
		return false;
	}
}

bool BoardManager::createPiece() {
	if (gameboard[pieceStartingCoords.Y][pieceStartingCoords.X] == 0) {
		piecePosition = pieceStartingCoords;
		randomizeCurrentPiece();
		return true;
	}
	else {
		return false;
	}
}

void BoardManager::clearBoard() {
	
	// Set the walls of the board to wall
	for (int y = 0; y < boardHeight; y++) {
		for (int x = 0; x < boardWidth; x++) {
			gameboard[y][x] = empty;
		}
	}
}