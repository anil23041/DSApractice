#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans) {
        if (open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }
        if (open == close) {
            solve(op + '(', open - 1, close, ans);
        } 
        else if (open == 0) {
            solve(op + ')', open, close - 1, ans);
        } 
        else if (close == 0) {
            solve(op + '(', open - 1, close, ans);
        } 
        else {
            solve(op + '(', open - 1, close, ans);
            solve(op + ')', open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n, ans);
        return ans;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(n);

    for (auto &str : res) 
        cout << str << endl;

    return 0;
}
