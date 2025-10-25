#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// MyLinkedList class
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        if (index == 0) return head->val;
        if (index == size - 1) return tail->val;

        Node* temp = head;
        for (int i = 1; i <= index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = new Node(val);
        Node* t = head;
        for (int i = 1; i <= index - 1; i++) {
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            head = head->next;
            size--;
            if (size == 0) tail = NULL; // update tail if list becomes empty
            return;
        }

        Node* temp = head;
        for (int i = 1; i <= index - 1; i++) {
            temp = temp->next;
        }

        if (index == size - 1) {
            temp->next = NULL;
            tail = temp;
        } else {
            temp->next = temp->next->next;
        }

        size--;
    }

    // Helper to print linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    MyLinkedList list;

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);  // List: 1 -> 2 -> 3
    list.printList();

    cout << "Value at index 1: " << list.get(1) << endl; // 2

    list.deleteAtIndex(1);  // List: 1 -> 3
    list.printList();

    cout << "Value at index 1: " << list.get(1) << endl; // 3

    list.addAtHead(4);       // List: 4 -> 1 -> 3
    list.addAtTail(5);       // List: 4 -> 1 -> 3 -> 5
    list.printList();

    return 0;
}
