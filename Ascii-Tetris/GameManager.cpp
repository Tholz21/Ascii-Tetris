#include "GameManager.h"


int GameManager::score = 0;

bool GameManager::startScreen() {
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
	int frameCounter = 0;
	bool running = TRUE;
	Renderer::renderGameTitle();

	while(running)
	{
		const auto startTime = steady_clock::now();

		InputHandler::getInputs();


		const auto endTime = steady_clock::now();
		TimeUtils::enforceFrameRate(startTime, endTime);
	}

	return score;
}