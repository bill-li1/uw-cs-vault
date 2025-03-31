#ifndef TICTAC_H
#define TICTAC_H
#include <string>

// Data for a Tic Tac Toe game.
struct TicTacGame {
	// each position in the board starts with an empty space ' '
	// and is modified to 'X' or 'O' as players make their moves
    char board[9];
	// the turn specifies if the next move will be an 'X' or 'O'
    char turn;
	// winner is initialized with a null character
	// and is modified to 'X' or 'O' when one of the players win,
	// or to 'D' if the game ends in a draw
    char winner;
};
    
// Initializes all the positions of the board to
// a whitespace char, the current turn to 'X',
// and the winner to 0.
void init(TicTacGame &game);

// Adds the player's symbol to the board in the specified position.
// Return true if the move was valid (i.e., the position was previously empty).
// Assumes that the pos is valid.
bool playTurn(TicTacGame &game, std::string &pos);

// Returns true if the game is over
// (which occurs when a player wins or when the board is all filled).
bool checkGameOver(TicTacGame &game);

// Prints the game board to cout.
void printBoard(const TicTacGame &game);

// Prints the winner to cout.
void printWinner(const TicTacGame &game);

#endif
