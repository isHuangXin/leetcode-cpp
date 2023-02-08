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

// Problem 103
// Link: https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

// note
// 双端队列 deque，push_back(), push_front()
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> bfs;
        if (root == nullptr) {
            return bfs;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool isLeftOrder = true;
        while(!q.empty()) {
            deque<int> layer;
            int currentLevelSize = q.size();
            for (int i = 0; i < currentLevelSize; i++) {
                auto node = q.front();
                q.pop();
                if (isLeftOrder) {
                    layer.push_back(node->val);
                } else {
                    layer.push_front(node->val);
                }
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }    
            bfs.emplace_back(vector<int>{layer.begin(), layer.end()});
            isLeftOrder = !isLeftOrder;
        }
        return bfs;
    }
};
