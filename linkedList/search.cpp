#include <iostream>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Linked List class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = nullptr;
    }

    // Add node at the tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Search for an element
    bool search(int target) {
        Node* temp = head;
        while (temp) {
            if (temp->val == target) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print linked list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    // Insert some elements
    list.addAtTail(10);
    list.addAtTail(20);
    list.addAtTail(30);
    list.addAtTail(40);

    cout << "Linked list: ";
    list.printList();

    // Search elements
    int target;
    cout << "Enter element to search: ";
    cin >> target;

    if (list.search(target)) {
        cout << target << " found in the linked list.\n";
    } else {
        cout << target << " not found in the linked list.\n";
    }

    return 0;
}
