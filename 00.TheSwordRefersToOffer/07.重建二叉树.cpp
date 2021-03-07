//
// Created by Huangxin's macbook air on 3/7/21.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> preorder;
    unordered_map<int,int> dic;
    TreeNode* recur(int root, int left, int right){
        if(left>right)
            return nullptr; // 递归终止条件
        TreeNode* node = new TreeNode(preorder[root]); //建立根节点
        int i = dit[preorder[root]]; // 划分根节点, 左子树, 右子树
        node->left = recur(root+1, left, i-1); // 左子树递归
        node->right = recur(root+i-left+1, i+1, right); // 右子树递归
        return node; // 回朔返回根节点
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i=0; i< inorder.size(); i++)
            dic[inorder[i]] = i;
        return recur(0, 0, inorder.size()-1);
    }
};
