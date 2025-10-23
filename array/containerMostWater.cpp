#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;

        while (i < j) {
            // Calculate the current area
            int area = (j - i) * min(height[i], height[j]);
            res = max(res, area);

            // Move the pointer pointing to the smaller height
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return res; 
    }
};

int main() {
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum water area: " << sol.maxArea(height) << endl;

    return 0;
}
