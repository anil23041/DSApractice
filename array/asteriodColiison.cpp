#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;

        for (int i = 0; i < n; i++) {
            // Case 1: Positive asteroid or stack empty → just push
            if (ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            } 
            else {
                // Case 2: Collision possible
                while (!s.empty() && s.top() > 0 && s.top() < abs(ast[i])) {
                    s.pop(); // Destroy smaller right-moving asteroids
                }

                // If same size, both destroy each other
                if (!s.empty() && s.top() == abs(ast[i])) {
                    s.pop();
                } 
                else {
                    // If stack empty or top is negative (same direction), push current
                    if (s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }

        // Convert stack to vector in correct order
        vector<int> res(s.size());
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Remaining asteroids after collisions: ";
    for (int a : result) cout << a << " ";
    cout << endl;

    // You can test more cases
    vector<int> test2 = {8, -8};
    vector<int> res2 = sol.asteroidCollision(test2);
    cout << "Case 2: ";
    for (int a : res2) cout << a << " ";
    cout << endl;

    vector<int> test3 = {10, 2, -5};
    vector<int> res3 = sol.asteroidCollision(test3);
    cout << "Case 3: ";
    for (int a : res3) cout << a << " ";
    cout << endl;

    return 0;
}
