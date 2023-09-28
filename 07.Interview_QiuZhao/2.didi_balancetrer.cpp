//
// Created by huangxin on 2023/9/28.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x): val(x) {};
};

TreeNode* buildTree(vector<TreeNode*>&nodes, vector<int>& parents) {
    for (int i = 0; i < nodes.size(); i++) {
        int parent = parents[i];
        if (parent != -1) {
            nodes[parent-1]->children.push_back(nodes[i]);
        }
    }
}

int calculateDistanceSum(TreeNode* root, int x) {
    queue<TreeNode*> q;
    q.push(root);
    int distance = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        bool foundX = false;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            if (current->val == x) {
                foundX = true;
                break;
            }
            for (TreeNode* child : current->children) {
                q.push(child);
            }
        }
        if (foundX) {
            break;
        }
        distance++;
    }
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<TreeNode*> nodes(n);
    vector<int> parents(n);

    for (int i = 0; i < n; ++i) {
        cin >> parents[i];
        nodes[i] = new TreeNode(i+1);
    }
    buildTree(nodes, parents);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int distanceSum = calculateDistanceSum(nodes[0], x);
        cout << distanceSum << " ";
    }
    cout << endl;

    for (TreeNode* node:nodes) {
        delete node;
    }
    return 0;
}