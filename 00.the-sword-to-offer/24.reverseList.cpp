//
// Created by huangxin on 1/17/22.
//

/**
 * Definition for singly-linked list.copyRandomList
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* cur;
    ListNode* pre;
    ListNode* temp;
public:
    ListNode* reverseList(ListNode* head) {
        cur = NULL, pre=head;
        while (pre != NULL){
            temp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};