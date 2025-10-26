#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        
        while (current != nullptr) {
            ListNode* nextNode = current->next;  // store next node
            current->next = prev;                // reverse current node's pointer
            prev = current;                      // move prev forward
            current = nextNode;                  // move current forward
        }
        
        return prev; // new head of reversed list
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}
