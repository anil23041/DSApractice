#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return; // cannot delete last node
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }
};

// Helper to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original list:\n";
    printList(head);

    // Delete node with value 5
    Solution sol;
    ListNode* nodeToDelete = head->next; // node with value 5
    sol.deleteNode(nodeToDelete);

    cout << "\nList after deleting node 5:\n";
    printList(head);

    // Free remaining memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
