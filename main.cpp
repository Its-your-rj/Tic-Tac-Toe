#include <iostream>
using namespace std;

char board[3][3];
char current_marker;
char current_player;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = current_marker;
    return true;
}

char checkWinner() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' ';
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == '1') {
        current_player = '2';
    } else {
        current_player = '1';
    }
}

void game() {
    cout << "Player one, choose your marker: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = '1';
    current_marker = marker_p1;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    drawBoard();
    
    int player_won;
    for (int i = 0; i < 9; i++) {
        cout << "It's player " << current_player << "'s turn. Enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(row, col)) {
            cout << "That position is occupied! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        char winner = checkWinner();
        if (winner == 'X') {
            cout << "Player 1 wins! Congratulations!" << endl;
            break;
        }
        if (winner == 'O') {
            cout << "Player 2 wins! Congratulations!" << endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (checkWinner() == ' ') {
        cout << "It's a tie!" << endl;
    }
}

int main() {
    game();
    return 0;
}
