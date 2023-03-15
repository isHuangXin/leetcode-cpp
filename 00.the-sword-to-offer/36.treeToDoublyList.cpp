#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *pre = nullptr;
    Node *head = nullptr;
    void dfs(Node* cur) {
        if(cur == nullptr) return;
        dfs(cur->left);
        if(pre != nullptr)
            pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        dfs(root); // 对二叉搜索树进行先序遍历得升序的数组
        head->left = pre;
        pre->right = head;
        return head;
    }
};

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution solution;
    Node* res = solution.treeToDoublyList(root);
    return 0;
}
