#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> count(10, 0); 

        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;  // exact match  bull
            } else {
                int s = secret[i] - '0';
                int g = guess[i] - '0';

               
                if (count[s] < 0) cows++;

               
                if (count[g] > 0) cows++;

                count[s]++;
                count[g]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    string secret, guess;

    cout << "Enter secret number: ";
    cin >> secret;

    cout << "Enter guess number: ";
    cin >> guess;

    Solution sol;
    string result = sol.getHint(secret, guess);

    cout << "Hint: " << result << endl;

    return 0;
}
