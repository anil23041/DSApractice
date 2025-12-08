#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> mp;   // prefixSum → first index
        int prefixSum = 0;
        int maxLen = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // subarray from 0 to i has sum 0
            if(prefixSum == 0) {
                maxLen = i + 1;
            }

            //  prefixSum seen before
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            } 
            else {
                // store first occurrence   prefixSum
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    Solution s;
    cout << s.maxLength(arr);
    return 0;
}
