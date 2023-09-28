//
// Created by huangxin on 2023/9/27.
//
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode();
        ListNode* p = res;

        stack<ListNode*> stk;
        while (head != nullptr) {
            stk.push(head);
            head = head->next;
            if (stk.size() == k) {
                while (!stk.empty()) {
                    p->next = stk.top();
                    stk.pop();
                    p = p->next;
                }
                p->next = nullptr;
            }
        }

        stack<ListNode*> last_k_stk;
        while (!stk.empty()) {
            ListNode* top = stk.top();
            last_k_stk.push(top);
            stk.pop();
        }
        while (!last_k_stk.empty()) {
            p->next = last_k_stk.top();
            last_k_stk.pop();
            p = p->next;
        }
        return res->next;
    }
};

int main () {
    // 创建节点
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    // 打印链表的值
    cout << "翻转前: ";
    ListNode* current = node1;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    int k = 3;

    Solution solution;
    ListNode* reverse_head = solution.reverseKGroup(node1, k);

    cout << "翻转后: ";
    ListNode* current_reverse = reverse_head;
    while (current_reverse != nullptr) {
        std::cout << current_reverse->val << " ";
        current_reverse = current_reverse->next;
    }

    // 释放内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}