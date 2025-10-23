#include <bits/stdc++.h>
using namespace std;

class myQueue {
private:
    int *arr;     // Array to store queue elements
    int front;    // Index of front element
    int rear;     // Index of rear element
    int size;     // Maximum size of the queue
    int count;    // Current number of elements

public:
    // Constructor
    myQueue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == size;
    }

    // Add an element to the rear of queue
    void enqueue(int x) {
        if (isFull()) return; // No insertion if full
        rear = (rear + 1) % size;
        arr[rear] = x;
        count++;
    }

    // Remove element from front
    void dequeue() {
        if (isEmpty()) return; // Nothing to remove
        front = (front + 1) % size;
        count--;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

// --------------------- DRIVER CODE ------------------------
int main() {
    int n = 3; // size of queue
    vector<vector<int>> queries = {
        {1, 5}, {1, 3}, {1, 4}, {3}, {2}, {5}, {4}
    };

    myQueue q(n);
    vector<string> output;  // store outputs as strings (to print true/false)

    for (auto query : queries) {
        if (query[0] == 1) q.enqueue(query[1]);
        else if (query[0] == 2) q.dequeue();
        else if (query[0] == 3) output.push_back(to_string(q.getFront()));
        else if (query[0] == 4) output.push_back(to_string(q.getRear()));
        else if (query[0] == 5) output.push_back(q.isEmpty() ? "false" : "true"); // per problem example
        else if (query[0] == 6) output.push_back(q.isFull() ? "true" : "false");
    }

    cout << "Output: [";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
