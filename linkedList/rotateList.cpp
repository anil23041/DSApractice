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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || head->next == nullptr) {
            return head; // empty list or single node
        }

        // Step 1: Count the length of the list
        ListNode* ptr = head;
        int count = 1;
        while (ptr->next != nullptr) {
            count++;
            ptr = ptr->next;
        }

        // Step 2: Make the list circular
        ptr->next = head;

        // Step 3: Find the new tail: (count - k % count - 1)th node
        k = k % count;
        int stepsToNewTail = count - k - 1;
        ptr = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            ptr = ptr->next;
        }

        // Step 4: Break the circle and set new head
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;

        return newHead;
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
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    int k = 2;
    ListNode* rotated = sol.rotateRight(head, k);

    std::cout << "List after rotating by " << k << ": ";
    printList(rotated);

    return 0;
}
