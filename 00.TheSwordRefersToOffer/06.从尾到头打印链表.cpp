//
// Created by Huangxin's macbook air on 1/28/21.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode* iter = head->next;
        vector<int> res;
        stack<int> temp;
        while(iter != NULL){
            temp.push(iter->val);
            iter = iter->next;
        }
        while(!temp.empty()){
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};

int main(){
    int l1_arr[3] = {1, 2, 3};
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

    Solution solution;
    vector<int> res = solution.reversePrint(l1_head);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
