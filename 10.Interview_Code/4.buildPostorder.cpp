//
// Created by huangxin on 2023/9/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void buildPostorderRecursive(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right, vector<int>& postorder, unordered_map<int, int>& inorder_index_map) {
    if (pre_left > pre_right) {
        return;
    }

    int root_value = preorder[pre_left];
    int root_inorder_idx = inorder_index_map[root_value];
    int left_tree_size = root_inorder_idx - in_left;

    // 递归构建左子树的后序遍历序列
    buildPostorderRecursive(preorder, inorder, pre_left + 1, pre_left + left_tree_size, in_left, root_inorder_idx - 1, postorder, inorder_index_map);

    // 递归构建右子树的后序遍历序列
    buildPostorderRecursive(preorder, inorder, pre_left + left_tree_size + 1, pre_right, root_inorder_idx + 1, in_right, postorder, inorder_index_map);

    // 添加根节点到后序遍历序列
    postorder.push_back(root_value);
}

vector<int> buildPostorder(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    vector<int> postorder;
    unordered_map<int, int> inorder_index_map;

    // 构建中序遍历序列中值到索引的映射，以便快速查找根节点的位置
    for (int i = 0; i < n; ++i) {
        inorder_index_map[inorder[i]] = i;
    }

    buildPostorderRecursive(preorder, inorder, 0, n - 1, 0, n - 1, postorder, inorder_index_map);

    return postorder;
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
/**
 * step 1:
 *                1
 *     {4 2 5}        {6, 3, 7}
 *
 * step 2:
 *                   1
 *         2              {6, 3, 7}
 *     {4}   {5}          {6, 3, 7}
 *
 * step 3:
 *                  1
 *          2           3
 *      4      5    {6}    {7}
 *
 * step 4:
 *                   1
 *          2                3
 *     4        5        6       7
 * */

    vector<int> postorder = buildPostorder(preorder, inorder);

    cout << "后序遍历序列: ";
    for (int value : postorder) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}