#include "Renderer.h"
#include "GameManager.h"

using namespace std;

void Renderer::renderGame() {
	ConsoleUtils::resetCursorPosition(COORD{45,7});
	ConsoleUtils::setCursorInvisible();
	string boardString = "";
	for (int row = 0; row < BoardManager::boardHeight; row++) {
		for (int collumn = 0; collumn < BoardManager::boardWidth; collumn++) {
			switch (BoardManager::gameboard[row][collumn]) {
			case BoardManager::wall:
				boardString = boardString + "#" + " ";
				break;
			case BoardManager::empty:
				boardString = boardString + " " + " ";
				break;
			case BoardManager::piece:
				boardString = boardString + "O" + " ";
				break;
			case BoardManager::staticPiece:
				boardString = boardString + "0" + " ";
				break;
			default:
				break;
			}
		}
		boardString = boardString + "\n" + "					     ";
	}
	cout << boardString;
	cout << "        Score: " << GameManager::score;

}

void Renderer::renderStartScreen(){
	cout << 
R"(
		  ______                       __  __        ________           __                __           
		 /      \                     /  |/  |      /        |         /  |              /  |          
		/$$$$$$  |  _______   _______ $$/ $$/       $$$$$$$$/______   _$$ |_     ______  $$/   _______ 
		$$ |__$$ | /       | /       |/  |/  |         $$ | /      \ / $$   |   /      \ /  | /       |
		$$    $$ |/$$$$$$$/ /$$$$$$$/ $$ |$$ |         $$ |/$$$$$$  |$$$$$$/   /$$$$$$  |$$ |/$$$$$$$/ 
		$$$$$$$$ |$$      \ $$ |      $$ |$$ |         $$ |$$    $$ |  $$ | __ $$ |  $$/ $$ |$$      \     
		$$ |  $$ | $$$$$$  |$$ \_____ $$ |$$ |         $$ |$$$$$$$$/   $$ |/  |$$ |      $$ | $$$$$$  |
		$$ |  $$ |/     $$/ $$       |$$ |$$ |         $$ |$$       |  $$  $$/ $$ |      $$ |/     $$/ 
		$$/   $$/ $$$$$$$/   $$$$$$$/ $$/ $$/          $$/  $$$$$$$/    $$$$/  $$/       $$/ $$$$$$$/  


					     do you want to play? [y/n])";
}

void Renderer::renderGameTitle(){
	cout <<
R"(
				     _             _ _   _____    _        _      
				    / \   ___  ___(_|_) |_   _|__| |_ _ __(_)___  
				   / _ \ / __|/ __| | |   | |/ _ \ __| !__| / __| 
				  / ___ \\__ \ (__| | |   | |  __/ |_| |  | \__ \ 
				 /_/   \_\___/\___|_|_|   |_|\___|\__|_|  |_|___/ 

)";

}

void Renderer::renderEndScreen(int score)
{
	cout << R"(
					$$$$$$$\  $$$$$$\ $$$$$$$$\ $$$$$$$\  
					$$  __$$\ \_$$  _|$$  _____|$$  __$$\ 
					$$ |  $$ |  $$ |  $$ |      $$ |  $$ |
					$$ |  $$ |  $$ |  $$$$$\    $$ |  $$ |
					$$ |  $$ |  $$ |  $$  __|   $$ |  $$ |
					$$ |  $$ |  $$ |  $$ |      $$ |  $$ |
					$$$$$$$  |$$$$$$\ $$$$$$$$\ $$$$$$$  |
					\_______/ \______|\________|\_______/ 
                                      

)";

	cout << "					    you ended with a score of " << score << endl;
	cout << "				         Enter anything to go back to start: ";
}

