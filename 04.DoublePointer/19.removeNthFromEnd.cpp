// Problem: 19.删除链表第N个元素
// Link: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 预设指针
        ListNode* prev = new ListNode(0, head);
        ListNode* curr = prev;
        int currCount = 0;
        int deleteIndex = getLength(head)-n;
        while(curr->next) {
            if (currCount == deleteIndex) {
                curr->next = curr->next->next;
                break;
            }
            currCount += 1;
            curr = curr->next;
        }
        return prev->next;
    }
};