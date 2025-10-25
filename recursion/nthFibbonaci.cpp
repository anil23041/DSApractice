#include <iostream>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // Base cases
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        // Recursive case
        return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " 
         << sol.nthFibonacci(n) << endl;

    return 0;
}
