//
// Created by huangxin on 2023/9/25.
//

#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断链表是否有环
bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false; // 链表为空或只有一个节点，一定没有环
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) {
            return false; // 快指针到达链表末尾，没有环
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return true; // 快指针追上了慢指针，有环
}

int main() {
    // 创建一个有环的链表示例
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // 4指向2，形成环

    bool hasCycleResult = hasCycle(head);

    if (hasCycleResult) {
        cout << "链表有环" << endl;
    } else {
        cout << "链表没有环" << endl;
    }

    // 释放动态分配的节点内存
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
