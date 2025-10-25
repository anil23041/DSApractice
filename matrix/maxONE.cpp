#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int totalOnes = INT_MIN;
        int minRow = INT_MAX;

        for (int i = 0; i < m; i++) {
            int onesCount = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    onesCount++;
            }

            // Update when we find more 1s
            if (totalOnes < onesCount) {
                minRow = i;
                totalOnes = onesCount;
            }
        }

        return {minRow, totalOnes};
    }
};

int main() {
    Solution sol;
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter matrix elements (only 0s and 1s):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> result = sol.rowAndMaximumOnes(mat);
    cout << "\nRow with maximum 1s: " << result[0] 
         << "\nNumber of 1s: " << result[1] << endl;

    return 0;
}
