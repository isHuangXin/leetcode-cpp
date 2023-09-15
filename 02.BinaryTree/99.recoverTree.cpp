/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    pair<int, int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int index_1 = -1, index_2 = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] < nums[i]) {
                index_2 = i + 1;
                if (index_1 == -1) {
                    index_1 = i;
                } else {
                    break;
                }
            }
        }
        int x = nums[index_1], y = nums[index_2];
        return {x, y};
    }

    void recover(TreeNode* root, int count, int x, int y) {
        if (root != nullptr) {
            if (root->val == x || root->val == y) {
                root->val = root->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(root->left, count, x, y);
            recover(root->right, count, x, y);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }
};
