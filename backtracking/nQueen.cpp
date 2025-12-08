#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool checkValid(int i, int j, vector<string>& board) {
        int n = board.size();

        
        for (int row = i - 1; row >= 0; row--) {
            if (board[row][j] == 'Q') return false;
        }

        
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
            if (board[row][col] == 'Q') return false;
        }

        
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++) {
            if (board[row][col] == 'Q') return false;
        }

        return true;
    }

  
    void solveNQueens(int row, vector<string>& board, vector<vector<string>>& result) {
        int n = board.size();
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            board[row][col] = 'Q'; 
            if (checkValid(row, col, board)) {
                solveNQueens(row + 1, board, result); 
            }

            board[row][col] = '.'; 
        }
    }

 
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); 
        solveNQueens(0, board, result);
        return result;
    }
};

int main() {
    Solution s;
    int n = 4;

    vector<vector<string>> solutions = s.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (auto &sol : solutions) {
        for (auto &row : sol) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
