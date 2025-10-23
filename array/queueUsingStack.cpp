#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    // Constructor
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element into s1
        s1.push(x);

        // Move everything back to s1 so that front of queue is on top
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    // Get the front element
    int peek() {
        return s1.top();
    }

    // Returns true if the queue is empty
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;  // Should print 10
    cout << "Popped element: " << q.pop() << endl;  // Should print 10
    cout << "Front after pop: " << q.peek() << endl; // Should print 20

    q.push(40);
    cout << "Front after pushing 40: " << q.peek() << endl; // Should print 20

    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
