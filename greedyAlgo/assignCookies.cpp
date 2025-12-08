#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < s.size() && j < g.size()) {
            if (g[j] <= s[i]) j++;
            i++;
        }
        return j;
    }
};

int main() {
    Solution s;
    vector<int> g = {1, 2, 3};
    vector<int> cookies = {1, 1};
    
    cout << s.findContentChildren(g, cookies);
    return 0;
}
