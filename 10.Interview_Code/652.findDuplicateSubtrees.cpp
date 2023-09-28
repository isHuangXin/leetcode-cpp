//
// Created by huangxin on 2023/9/27.
//
#include <iostream>
#include <vector>
#include <unordered_map>

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
    string dfs(TreeNode* root, unordered_map<string, int> umap, vector<TreeNode*> res) {
        if (root == nullptr) {
            return "";
        }
        string rs = to_string(root->val) + "," + dfs(root->left, umap, res) + "," + dfs(root->right, umap, res);
        umap[rs]++;
        if (umap[rs] == 2) {
            res.push_back(root);
        }
        return rs;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> umap;
        dfs(root, umap, res);
        return res;
    }
};

int main() {

}