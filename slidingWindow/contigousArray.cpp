
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int zeroes = 0, ones = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 0)
                    zeroes++;
                else
                    ones++;

                if (zeroes == ones)
                    maxlen = max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter 0s and 1s: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << "Maximum length of subarray with equal 0s and 1s = "
         << sol.findMaxLength(nums) << endl;

    return 0;
}
