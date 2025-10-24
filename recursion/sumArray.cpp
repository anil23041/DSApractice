#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive function to return sum of elements
    int arraySum(vector<int>& arr, int n) {
        // Base case: if array size is 0, sum is 0
        if (n == 0) {
            return 0;
        }
        // Recursive case: sum of first n-1 elements + last element
        return arraySum(arr, n - 1) + arr[n - 1];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = sol.arraySum(arr, n);
    cout << "Sum of array elements = " << result << endl;

    return 0;
}
