#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nextGreater(n, -1); 
        stack<int> s;

        // Step 1: Build next greater element array for nums2
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                nextGreater[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }

        // Step 2: Map each value in nums2 to its next greater element
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums2[i]] = nextGreater[i];
        }

        // Step 3: Build result for nums1 using the map
        vector<int> result;
        for (int val : nums1) {
            result.push_back(mp[val]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
