#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> v;  // Array to store elements
    int rear = 0;   // Points to the next insertion position
    int front = 0;  // Points to the current front element
    int n;          // Size of the circular queue (including one extra slot)

    // Constructor
    MyCircularQueue(int k) {
        v = vector<int>(k + 1);  // One extra space to differentiate full vs empty
        n = k + 1;
    }

    // Insert an element into the circular queue
    bool enQueue(int value) {
        if (isFull()) return false;
        v[rear] = value;
        rear = (rear + 1) % n;
        return true;
    }

    // Delete an element from the circular queue
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % n;
        return true;
    }

    // Get the front item
    int Front() {
        if (isEmpty()) return -1;
        return v[front];
    }

    // Get the last item
    int Rear() {
        if (isEmpty()) return -1;
        int idx = (rear == 0) ? n - 1 : rear - 1;
        return v[idx];
    }

    // Check whether the circular queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Check whether the circular queue is full
    bool isFull() {
        return (rear + 1) % n == front;
    }
};

int main() {
    MyCircularQueue q(3);  // Queue capacity = 3

    cout << boolalpha;  // Print true/false instead of 1/0

    cout << "enQueue(1): " << q.enQueue(1) << endl;  // true
    cout << "enQueue(2): " << q.enQueue(2) << endl;  // true
    cout << "enQueue(3): " << q.enQueue(3) << endl;  // true
    cout << "enQueue(4): " << q.enQueue(4) << endl;  // false (queue full)

    cout << "Rear: " << q.Rear() << endl;    // 3
    cout << "IsFull: " << q.isFull() << endl; // true

    cout << "deQueue: " << q.deQueue() << endl; // true
    cout << "enQueue(4): " << q.enQueue(4) << endl; // true
    cout << "Rear: " << q.Rear() << endl;    // 4
    cout << "Front: " << q.Front() << endl;  // 2

    cout << "IsEmpty: " << q.isEmpty() << endl; // false

    return 0;
}
