#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, nums, current, result);
        return result;
    }

private:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
       
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        generateSubsets(index + 1, nums, current, result);
        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, result);
        current.pop_back();
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
    vector<vector<int>> allSubsets = sol.subsets(nums);

    cout << "All subsets: [";
    for (int i = 0; i < allSubsets.size(); i++) {
        cout << "[";
        for (int j = 0; j < allSubsets[i].size(); j++) {
            cout << allSubsets[i][j];
            if (j < allSubsets[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < allSubsets.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
