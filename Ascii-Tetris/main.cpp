#include "GameManager.h"
int main() {
	int endScore{ 0 };
	while (GameManager::startScreen()) {
		endScore = GameManager::startGame();
		BoardManager::clearBoard();
		GameManager::endScreen(endScore);
	}

	return 1;
}