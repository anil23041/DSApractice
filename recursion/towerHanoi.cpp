#include <iostream>
using namespace std;

class Solution {
  public:
    // Function to solve Tower of Hanoi and count moves
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0)
            return 0;

        // Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
        int moves1 = towerOfHanoi(n - 1, from, aux, to);

        // Move the nth disk from 'from' to 'to'
        cout << "Move disk " << n << " from rod " << from 
             << " to rod " << to << endl;
        int moves2 = 1;

        // Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
        int moves3 = towerOfHanoi(n - 1, aux, to, from);

        return moves1 + moves2 + moves3;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSequence of moves:\n";
    int totalMoves = sol.towerOfHanoi(n, 1, 3, 2);

    cout << "\nTotal moves required: " << totalMoves << endl;

    return 0;
}
