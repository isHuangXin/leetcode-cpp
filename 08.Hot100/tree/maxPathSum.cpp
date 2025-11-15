#include <iostream>
using namespace std;

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) {
            return 0;
        }

        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);
        // currentPathSum 是什么意思
        // currentPathSum 代表以当前节点为根节点的路径和，包括左子树和右子树的最大贡献值
        // 它用于更新全局最大路径和 maxSum
        int currentPathSum = node->val + leftGain + rightGain;
        maxSum = max(maxSum, currentPathSum);
        // 为什么是 value + max(leftGain, rightGain)？
        // 因为在计算当前节点对其父节点的最大贡献值时，我们只能选择左子树或右子树中的一个
        // 以确保路径的连续性
        // 为什么不是 currentPathSum？
        // 因为 currentPathSum 包含了左子树和右子树的贡献值，而在向上返回给父节点时
        // 只能选择其中一个子树的贡献值，以保持路径的连续性
        return node->val + max(leftGain, rightGain);
    }
};


int main() {
    // 输入：root = [-10,9,20,null,null,15,7]
    // 输出：42
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution sol;
    int result = sol.maxPathSum(root);
    cout << "Max Path Sum: " << result << endl;
    return 0;
}