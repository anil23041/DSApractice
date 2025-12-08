#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++) {
            
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution sol;
    cout << "Length of Longest Substring Without Repeating Characters = "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
