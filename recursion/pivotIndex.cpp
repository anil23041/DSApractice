#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int leftSum = 0, rightSum = 0;

            // Sum of left side
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }

            // Sum of right side
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            if (leftSum == rightSum) {
                return i; // Found pivot index
            }
        }

        return -1; // No pivot found
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int result = sol.pivotIndex(nums);
    cout << "Pivot Index: " << result << endl;

    return 0;
}
