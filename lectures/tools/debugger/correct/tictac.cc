#include <iostream>
#include <string>
#include "tictac.h"
using namespace std;

void init(TicTacGame &game) {
    for (int i = 0; i < 9; ++i) {
        game.board[i] = ' ';
    }
	game.turn = 'X';
    game.winner = 0;
}

bool playTurn(TicTacGame &game, std::string &pos) {
    int r = pos[0] - 'a';
    int c = pos[1] - '1';
    if (game.board[(3 * r) + c] != ' ') {
        cout << "Invalid position." << endl;
        return false;
    } else {
        game.board[(3 * r) + c] = game.turn;
        game.turn = (game.turn == 'X') ? 'O' : 'X';
		return true;
    }
}

bool checkGameOver(TicTacGame &game) {
    // check for winning rows
    for (int r = 0; r < 3; ++r) {
        int p = 3 * r;
        if (game.board[p] == game.board[p + 1]
            && game.board[p + 1] == game.board[p + 2]
            && game.board[p] != ' ') {
            game.winner = game.board[p];
            return true;
        }
    }
    // check for winning columns
    for (int c = 0; c < 3; ++c) {
        if (game.board[c] == game.board[3 + c]
            && game.board[3 + c] == game.board[6 + c]
            && game.board[c] != ' ') {
            game.winner = game.board[c];
            return true;
        }
    }
    // check for winning diagonals
    if (game.board[0] == game.board[4]
        && game.board[4] == game.board[8]
        && game.board[0] != ' ') {
        game.winner = game.board[0];
        return true;
    } else if (game.board[2] == game.board[4]
        && game.board[4] == game.board[6]
        && game.board[2] != ' ') {
        game.winner = game.board[2];
        return true;
    } else {
    // check if it's a draw (board is filled without winner)
        bool filled = true;
        for (int i = 0; i < 9; ++i) {
            if (game.board[i] == ' ') {
                filled = false;
                break;
            }
        }
        if (filled) {
            game.winner = 'D';
            return true;
        }
    }
    return false;
}

void printBoard(const TicTacGame &game) {
    cout << endl << "  1   2   3" << endl;
    for (int r = 0; r < 3; ++r) {
        char rc = 'a' + r;
        cout << rc << " ";
        for (int c = 0; c < 3; ++c) {
            cout << game.board[(3 * r) + c];
            if (c < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (r < 2) {
            cout << " ---+---+---" << endl;
        }
    }
}

void printWinner(const TicTacGame &game) {
    if (game.winner == 'D') {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << game.winner << " won!" << endl;
    }
}
