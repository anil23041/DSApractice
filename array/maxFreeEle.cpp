#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count[101] = {0};  // Frequency array for elements in range [1, 100]
        int maxFreq = 0;

        // Step 1: Count frequency of each element and find max frequency
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
        }

        // Step 2: Count how many total elements have that max frequency
        int total = 0;
        for (int i = 1; i <= 100; i++) {
            if (count[i] == maxFreq) {
                total += count[i];
            }
        }

        return total;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    cout << sol.maxFrequencyElements(nums) << endl;
    return 0;
}
