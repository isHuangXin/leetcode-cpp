//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> unorderedSet;
        ListNode* curr_headA = headA;
        while (curr_headA!= nullptr) {
            unorderedSet.insert(curr_headA);
            curr_headA = curr_headA->next;
        }
        ListNode* curr_headB = headB;
        while (curr_headB!= nullptr) {
            if(unorderedSet.count(curr_headB)) {
                return curr_headB;
            }
            curr_headB = curr_headB->next;
        }
        return nullptr;
    }
};
