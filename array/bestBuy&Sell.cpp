#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];  // Minimum price to buy so far
        int profit = 0;       // Maximum profit so far

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];  // Found a cheaper buying price
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;  // Found a higher profit
            }
        }

        return profit;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
