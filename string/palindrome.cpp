#include <iostream>
#include <string>
#include <cctype>  // for isalnum() and tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i <= j) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
};

// Example usage
int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (sol.isPalindrome(s))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
