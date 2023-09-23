//
// Created by huangxin on 2023/9/15.
//

// 合并二叉树
#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    TreeNode* mergeTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        TreeNode* merged = new TreeNode(t1->val + t2->val);
        merged->left = merged(t1->left, t2->left);
        merged->right = merged(t1->right, t2->right);
        return merged;
    }
};


int main() {
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(5);
    t2->left = new TreeNode(3);
    t2->left->left = new TreeNode(2);
    t2->right = new TreeNode(6);
    t2->right->left = new TreeNode(1);
    t2->right->right = new TreeNode(4);

    Solution solution;
    solution.mergeTree(t1, t2);
}