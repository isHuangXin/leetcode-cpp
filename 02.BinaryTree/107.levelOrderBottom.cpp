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

// Problem 107
// Link: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/solution/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bottomBfs;
        vector<vector<int>> bfs;
        if (root == nullptr) {
            return bottomBfs;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            vector<int> layer;
            for (int i = 0; i < currentLevelSize; i++) {
                auto node = q.front();
                q.pop();
                layer.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            bfs.push_back(layer);
        }

        for (int i = 0; i < bfs.size(); i++) {
            bottomBfs.push_back(bfs[bfs.size()-1-i]);
        }
        return bottomBfs;
    }
};
