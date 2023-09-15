//
// Created by huangxin on 2023/8/17.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val): val(_val), next(nullptr) {};
};

bool isCycle(ListNode* head) {
    if(!head || !head->next) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;        // 慢指针前进一步
        fast = fast->next->next;  // 快指针前进两步
        if(slow == fast) {
            return true; // 慢指针和快指针相遇，说明有环
        }
    }
    return false; // 慢指针和快指针相遇，说明有环
}

int main() {
    // Create a linked list with a cycle for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Creating a cycle

    if (isCycle(head)) {
        std::cout << "The linked list contains a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not contain a cycle." << std::endl;
    }

    // Clean up memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}

