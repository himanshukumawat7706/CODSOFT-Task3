#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';
int choice;
bool gameOver = false;

void displayBoard() {
    cout << "Current Board:" << endl;
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--+---+--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--+---+--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playerMove() {
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    // Map the choice to board positions
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Validate move
    if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move! Try again." << endl;
        playerMove();  // Recursive call for valid move
    }
}

void resetBoard() {
    char counter = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = counter++;
        }
    }
}

int main() {
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        gameOver = false;
        resetBoard();
        currentPlayer = 'X';

        while (!gameOver) {
            displayBoard();
            playerMove();

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }

    return 0;
}
