#include <bits/stdc++.h>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(vector<string>& arr) {
    stack<long long> st; // use long long for safety

    for (auto &token : arr) {
        // If token is an operator
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long res = 0;

            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                // Floor division for negatives as well
                if (a * b < 0 && a % b != 0)
                    res = a / b - 1;
                else
                    res = a / b;
            } 
            else if (token == "^") res = pow(a, b);

            st.push(res);
        } 
        else {
            // Operand
            st.push(stoi(token));
        }
    }

    return (int)st.top();
}

int main() {
 
    vector<string> arr1 = {"2", "3", "1", "*", "+", "9", "-"};
    cout << "Output 1: " << evaluatePostfix(arr1) << endl; 
   
    vector<string> arr2 = {"2", "3", "^", "1", "+"};
    cout << "Output 2: " << evaluatePostfix(arr2) << endl;
   
    vector<string> arr3 = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
    cout << "Output 3: " << evaluatePostfix(arr3) << endl;
  

    return 0;
}
