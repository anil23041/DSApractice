#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int original = n;
        int count = 0;

        while (n > 0) {
            int digit = n % 10;  // Extract the last digit
            n = n / 10;          // Remove the last digit
            
            // Check if digit is non-zero and divides the original number
            if (digit != 0 && original % digit == 0) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sol.evenlyDivides(n);
    cout << "Count of digits that evenly divide " << n << " = " << result << endl;

    return 0;
}
