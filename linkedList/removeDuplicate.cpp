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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;  // Keep the head pointer

        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;  // Skip the duplicate
            } else {
                head = head->next;  // Move forward
            }
        }

        return res;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* unique = sol.deleteDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(unique);

    return 0;
}
