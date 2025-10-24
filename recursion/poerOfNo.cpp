#include <iostream>
#include <cmath>    // for pow()
using namespace std;

// Function to reverse digits of a number
int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

// Function to compute n raised to the power of its reverse
int reverseExponentiation(int n) {
    int rev = reverseNumber(n);
    // Use pow() carefully, casting result to int
    return static_cast<int>(pow(n, rev));
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = reverseExponentiation(n);
    cout << n << "^" << reverseNumber(n) << " = " << result << endl;

    return 0;
}
