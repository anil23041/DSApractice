#include <iostream>
#include <string>
using namespace std;

class Stack {
    int top;        // Index of top element
    char arr[1000]; // Fixed-size array for stack
public:
    Stack() { top = -1; }

    // Push character onto stack
    void push(char c) {
        arr[++top] = c;
    }

    // Pop character from stack
    char pop() {
        if (top == -1) return '\0'; // Empty stack
        return arr[top--];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string s;
    getline(cin, s);  // Read input string

    Stack st;

    // Push all characters of string into stack
    for (char c : s) {
        st.push(c);
    }

    // Pop all characters to reverse the string
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    cout << endl;

    return 0;
}
