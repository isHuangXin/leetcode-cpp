//
// Created by huangxin on 1/17/22.
//

/**
 * Definition for singly-linked list.
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
    stack<int> temp;
    vector<int> res;
    ListNode* cur;
public:
    vector<int> reversePrint(ListNode* head) {
        cur = head;
        while (cur){
            temp.push(cur->val);
            cur = cur->next;
        }
        while (!temp.empty()){
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};