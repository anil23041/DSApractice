#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        // Step 1: Find indices of minimum and maximum elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // Step 2: Ensure minIdx < maxIdx for easier calculation
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        // Step 3: Compute three possible strategies
        int op1 = maxIdx + 1;                 // Delete from front
        int op2 = n - minIdx;                 // Delete from back
        int op3 = (minIdx + 1) + (n - maxIdx); // Delete from both ends

        // Step 4: Return the minimum number of deletions
        return min({op1, op2, op3});
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << sol.minimumDeletions(nums) << endl;
    return 0;
}
