//
// Created by huangxin on 2023/9/25.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 定义二叉树节点
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == nullptr) {
        return res;
    }

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        res.push_back(node->value);
        if(node->right) {
            nodeStack.push(node->right);
        }
        if (node->left) {
            nodeStack.push(node->left);
        }
    }
    return res;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodeStack;
    TreeNode* currentNode = root;
    while (!nodeStack.empty() || currentNode) {
        if (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            result.push_back(node->value);
            currentNode = node->right;
        }
    }
    return result;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root) {
        return result;
    }
    stack<TreeNode*> nodeStack;
    stack<int> resultStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        resultStack.push(node->value);
        if(node->left) {
            nodeStack.push(node->left);
        }
        if(node->right) {
            nodeStack.push(node->right);
        }
    }

    while (!resultStack.empty()) {
        result.push_back(resultStack.top());
        resultStack.pop();
    }

    return result;
}

int main() {
// 创建一个示例树
//       1
//    2      3
// 4     5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 调用先序遍历函数
    vector<int> preorderResult = preorderTraversal(root);
    // 输出遍历结果
    for (int val : preorderResult) {
        cout << val << " ";
    }
    cout << endl;

    // 调用中序遍历函数
    vector<int> inorderResult = inorderTraversal(root);
    // 输出遍历结果
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;

    // 调用中序遍历函数
    vector<int> postorderResult = postorderTraversal(root);
    // 输出遍历结果
    for (int val : postorderResult) {
        cout << val << " ";
    }
    cout << endl;

    // 释放动态分配的节点内存
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}




