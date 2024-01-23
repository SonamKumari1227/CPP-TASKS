#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>> &board);
bool updateBoard(vector<vector<char>> &board, int row, int col, char currentPlayer);
bool checkWin(const vector<vector<char>> &board, char currentPlayer);
bool checkDraw(const vector<vector<char>> &board);
char switchPlayer(char currentPlayer);
void displayResult(char result);

int main() {
    const int SIZE = 3;
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

    char currentPlayer = 'X';
    char result;

    do {
        displayBoard(board);

        int row, col;

        cout << "Player " << currentPlayer << ", enter your move (row and column, separated by space): ";
        cin >> row >> col;

        if (updateBoard(board, row, col, currentPlayer)) {
        
            if (checkWin(board, currentPlayer)) {
                result = currentPlayer;
            } else if (checkDraw(board)) {
                result = 'D'; 
            } else {
               
                currentPlayer = switchPlayer(currentPlayer);
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }

    } while (result == '\0');

    displayBoard(board);
    displayResult(result);

    return 0;
}

void displayBoard(const vector<vector<char>> &board) {
    cout << "\nCurrent Board:\n";
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << "\n";
    }
    cout << "-------------\n";
}

bool updateBoard(vector<vector<char>> &board, int row, int col, char currentPlayer) {
    if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWin(const vector<vector<char>> &board, char currentPlayer) {
   
    for (int i = 0; i < board.size(); ++i) {
  
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>> &board) {
 
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true; 
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult(char result) {
    if (result == 'D') {
        cout << "It's a draw!\n";
    } else {
        cout << "Player " << result << " wins!\n";
    }
}
