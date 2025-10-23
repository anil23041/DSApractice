#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        bool swapped;

        // Bubble sort implementation
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;  // Optimization: stop if already sorted
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << "Before sorting: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.sortColors(nums);

    cout << "After sorting:  ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
