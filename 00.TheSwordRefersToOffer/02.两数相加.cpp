//
// Created by Huangxin's macbook air on 1/27/21.
//

#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main(){
    int l1_arr[3] = {2, 4, 3};
    int l2_arr[3] = {5, 6, 4};
    ListNode* l1_head = new ListNode();
    ListNode* l1_end;
    l1_head->next = nullptr;
    l1_end = l1_head;
    for(int i=0; i< sizeof(l1_arr)/ sizeof(l1_arr[0]); i++){
        ListNode* l1_node = new ListNode();
        l1_node->val = l1_arr[i];
        l1_end->next = l1_node;
        l1_end = l1_node;
    }
    l1_end->next = nullptr;

    ListNode* l2_head = new ListNode();
    ListNode* l2_end;
    l2_head->next = nullptr;
    l2_end = l2_head;
    for(int i=0; i< sizeof(l2_arr)/ sizeof(l2_arr[0]); i++){
        ListNode* l2_node = new ListNode();
        l2_node->val = l2_arr[i];
        l2_end->next = l2_node;
        l2_end = l2_node;
    }
    l2_end->next = nullptr;

    Solution solution;
    ListNode* res = solution.addTwoNumbers(l1_head,l2_head);
    while (res != nullptr){
        cout<< res->val<<" ";
        res = res->next;
    }
    return 0;
}
