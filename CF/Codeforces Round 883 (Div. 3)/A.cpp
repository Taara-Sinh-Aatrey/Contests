#include <bits/stdc++.h>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if there is a winner
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;

    // Game loop
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            drawBoard(board);

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins! Congrats!" << endl;
                break;
            }

            // Check if the board is full (tie)
            bool boardFull = true;
            for (const auto& row : board) {
                for (const auto& cell : row) {
                    if (cell == ' ') {
                        boardFull = false;
                        break;
                    }
                }
            }
            if (boardFull) {
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch to the next player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Invalid move. Try again!" << endl;
        }
    }
}

// Main function
int main() {
    playGame();
    return 0;
}
