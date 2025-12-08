#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(arr.begin(), arr.end()); 
        backtrack(arr, 0, subset, result);
        return result;
    }

private:
    void backtrack(vector<int>& arr, int index, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);

        for (int i = index; i < arr.size(); i++) {
           
            if (i > index && arr[i] == arr[i - 1]) continue;

            subset.push_back(arr[i]);
            backtrack(arr, i + 1, subset, result);
            subset.pop_back();
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 2};

    Solution sol;
    vector<vector<int>> subsets = sol.findSubsets(arr);

    cout << "[";
    for (int i = 0; i < subsets.size(); i++) {
        cout << "[";
        for (int j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j];
            if (j < subsets[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < subsets.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
