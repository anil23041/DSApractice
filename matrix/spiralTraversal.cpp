#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Left to Right
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            top++;

            // Top to Bottom
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            right--;

            // Right to Left
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = sol.spiralOrder(matrix);

    cout << "\nSpiral Order Traversal:\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
