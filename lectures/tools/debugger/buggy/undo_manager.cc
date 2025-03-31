#include <iostream>
#include <string>
#include "undo_manager.h"
using namespace std;

UndoHistory * addMove(UndoHistory *lastMove, const char board[9], const char lastPlayer, const std::string &lastPos) {
	UndoHistory * newMove = new UndoHistory;
	for (int i = 0; i < 9; ++i) {
        newMove->board[i] = board[i];
    }
	newMove->lastPlayer = lastPlayer;
	newMove->lastPos = lastPos;
	if (lastMove != nullptr) {
		newMove->previous = lastMove;
	} else {
		newMove->previous = nullptr;
	}
	newMove->next = nullptr;
	return newMove;
}

UndoHistory * undo(TicTacGame &game, UndoHistory *lastMove){
	if (lastMove == nullptr) {
		cout << "There is nothing to undo." << endl;
		return nullptr;
	}
	UndoHistory * previousState = lastMove->previous;
	// modifies the game back to the previous state
	for (int i = 0; i < 9; ++i) {
        game.board[i] = previousState->board[i];
    }
	game.turn = (game.turn == 'X') ? 'O' : 'X';
	game.winner = 0;
	cout << "Action undone." << endl;
	// updates the undo history
	previousState->next = nullptr;
	return previousState;
}

void list(const UndoHistory *firstMove) {
	if (firstMove == nullptr) {
		cout << "The players did not make any move yet." << endl;
		return;
	}
	const UndoHistory * current = firstMove;
	while (current != nullptr) {
		cout << current->lastPlayer << " played on " << current->lastPos << endl;
		current = current->next;
	}
}
