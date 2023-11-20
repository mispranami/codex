#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer;

// Function to display the Tic Tac Toe board
void displayBoard() {
    cout << "Tic Tac Toe Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (draw)
bool checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // Empty cell found
            }
        }
    }
    return true; // Board is full
}

// Function to switch to the other player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random symbol at the start
    currentPlayer = (rand() % 2 == 0) ? 'X' : 'O';

    int move;
    bool gameOver = false;

    do {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> move;

        // Validate user input
        if (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] == 'X' || board[(move - 1) / 3][(move - 1) % 3] == 'O') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Place X or O on the board
        board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;

        // Check for a win
        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw!" << endl;
            gameOver = true;
        } else {
            switchPlayer(); // Switch to the other player
        }

    } while (!gameOver);

    return 0;
}
