#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueens(vector<int>& board, int row, vector<vector<int>>& solutions) {
    int n = board.size();
    if (row == n) {
        // Found a valid solution, add it to the list
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, solutions);
            board[row] = -1;  // Backtrack
        }
    }
}

// Function to find all solutions to the N-Queens problem
vector<vector<int>> solveNQueens(int n) {
    vector<int> board(n, -1);  // Initialize the board with -1
    vector<vector<int>> solutions;
    solveNQueens(board, 0, solutions);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    vector<vector<int>> solutions = solveNQueens(n);

    if (solutions.empty()) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Found " << solutions.size() << " solution(s):" << endl;
        for (const vector<int>& solution : solutions) {
            printBoard(solution);
        }
    }

    return 0;
}
