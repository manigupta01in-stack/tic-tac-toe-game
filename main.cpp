#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void resetBoard() {
    char value = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

int main() {
    char playAgain;

    do {
        resetBoard();

        char currentPlayer = 'X';
        int move;

        cout << "\n===== TIC TAC TOE =====\n";

        while (true) {
            displayBoard();

            cout << "Player " << currentPlayer
                 << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid move! Choose a number from 1 to 9.\n";
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                cout << "That position is already occupied!\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";

    return 0;
}
