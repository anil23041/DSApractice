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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;               // Dummy node to simplify merging
        ListNode* tail = &dummy;      // Tail points to the last node in merged list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;   
                list1 = list1->next;  
            } else {
                tail->next = list2;   
                list2 = list2->next; 
            }
            tail = tail->next;        
        }

        // Attach the remaining nodes
        if (list1 != nullptr) tail->next = list1;
        if (list2 != nullptr) tail->next = list2;

        return dummy.next;  // Return the merged list head
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1, new ListNode(3, new ListNode(5)));

    // Create second sorted list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    std::cout << "Merged list: ";
    printList(merged);

    return 0;
}
