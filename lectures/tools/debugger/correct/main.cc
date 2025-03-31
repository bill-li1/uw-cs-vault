#include <iostream>
#include <string>
#include "tictac.h"
#include "undo_manager.h"
using namespace std;

void printHeader() {
	cout << "Tic Tac Toe game" << endl << endl;
	cout << "[row][column] to make a move (e.g., a1, b2, etc.)" << endl;
	cout << "[undo] to undo the last move" << endl;
	cout << "[list] to list all the moves done so far" << endl;
}

// Main function of the Tic Tac Toe game.
// The game loop is run in the main function. 
int main() {
    TicTacGame game;
	UndoHistory * firstMove = nullptr;
	UndoHistory * lastMove  = nullptr;
    string pos;
	init(game);
	printHeader();
	// Game loop
    while (true) {
        printBoard(game);
        cout << game.turn << "'s turn: ";
        cin >> pos;
        if (cin.eof()) {
            break;
        }
		if (pos == "list") {
			list(firstMove);
		} else if (pos == "undo") {
			lastMove = undo(game, lastMove);
        } else if (pos.length() < 2
            || pos[0] < 'a' || pos[0] > 'c'
            || pos[1] < '1' || pos[1] > '3') {
            cout << "Invalid move." << endl;
        } else {
			char currentPlayer = game.turn;
			// update the game state
            if (playTurn(game, pos)) {
			    // save move in the undo history
			    lastMove = addMove(lastMove, game.board, currentPlayer, pos);
			    if (firstMove == nullptr) firstMove = lastMove;
			}
			if (checkGameOver(game)) {
				// Print final game data
				printBoard(game);
				printWinner(game);
				break;
			}
        }
    }
	// Free dynamic memory
	UndoHistory * current = firstMove;
	while (current != nullptr) {
		UndoHistory * next = current->next;
		delete current;
		current = next;
	}
}
