#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void perms(int i, vector<vector<int>>& res, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            perms(i + 1, res, nums);
            swap(nums[i], nums[j]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perms(0, res, nums);
        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    vector<vector<int>> permutations = sol.permute(nums);

    cout << "All permutations: [";
    for (int i = 0; i < permutations.size(); i++) {
        cout << "[";
        for (int j = 0; j < permutations[i].size(); j++) {
            cout << permutations[i][j];
            if (j < permutations[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < permutations.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
