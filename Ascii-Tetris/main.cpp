#include "GameManager.h"
int main() {
	while (GameManager::startScreen()) {
		GameManager::startGame();
	}

	return 1;
}