#include <iostream>
using namespace std;

class Solution {
public:
    void printTillN(int n) {
        // Base case: stop when n reaches 0
        if (n == 0) {
            return;
        }
        
        // Recursive call: go down to 1 first
        printTillN(n - 1);
        
        // Print current number after recursion unwinds
        cout << n << " ";
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    sol.printTillN(n);
    cout << endl;
    
    return 0;
}
