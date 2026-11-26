#include "GameManager.h"


int GameManager::score = 0;
int spawnFrame = 5;

bool GameManager::startScreen() {
	ConsoleUtils::clearConsole();
	Renderer::renderStartScreen();
	char input;
	cin >> input;
	if (input == 'y') {
		system("cls");
		input = ' ';
		return true;
	}
	else {
		return false;
	};
}

int GameManager::startGame() {
	ConsoleUtils::clearConsole();
	int frameCounter = 0;
	bool running = TRUE;
	Renderer::renderGameTitle();
	BoardManager::instantiateBoard();
	BoardManager::createPiece();

	while(running)
	{
		frameCounter++;

		const auto startTime = steady_clock::now();

		InputHandler::getInputs();
		if(frameCounter % 5 == 0)
		{
			if (BoardManager::movePieceIfValid(COORD{ 0,1 })) {
				BoardManager::updateGameBoard(false);
			}
			else {
				BoardManager::updateGameBoard(true);
				BoardManager::checkAndClearFullLine();
				running = BoardManager::createPiece();
				score++;
			}
		}
		else {
			BoardManager::updateGameBoard(false);
		}
		Renderer::renderGame();

		const auto endTime = steady_clock::now();
		TimeUtils::enforceFrameRate(startTime, endTime);
	}


	return score;
}

void GameManager::endScreen(int score) {
	ConsoleUtils::clearConsole();


	char var = ' ';
	cin >> var;
	var = ' ';
}