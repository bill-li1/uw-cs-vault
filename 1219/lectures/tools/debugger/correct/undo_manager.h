#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H
#include <string>
#include "tictac.h"

// Data for each player move done in the game.
// (double-linked list)
struct UndoHistory {
	// state of the board after this move was done
	char board[9];
	// player who did this move ('X' or 'O')
	char lastPlayer;
	// position played this turn (e.g., a1, b2, etc.)
	std::string lastPos;
	// previous move in the history
	UndoHistory * previous;
	// next move in the history
	UndoHistory * next;
};

// Creates and returns a new UndoHistory with the data about the latest turn of the game.
// Also updates the previous lastMove to keep the double-linked list.
UndoHistory * addMove(UndoHistory *lastMove, const char board[9], const char lastPlayer, const std::string &lastPos);

// Undoes the last action by returning the game data to its previous state.
// Also deletes the latest move from the history, updates the double-linked list,
// and returns the new lastMove in the history.
UndoHistory * undo(TicTacGame &game, UndoHistory *lastMove);

// Prints the list of moves done so far to cout.
void list(const UndoHistory *firstMove);

#endif
