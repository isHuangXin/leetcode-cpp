#include <iostream>
#include <vector>
using namespace std;

class Solution {
// 给我解释用DFS方法计算岛屿数量的代码
// DFS (Depth-First Search) 方法用于遍历和标记岛屿中的所有陆地单元格
// 以避免重复计数。以下是代码的详细解释：
// 1. 主函数 numIslands:
//    - 初始化计数器 count 为 0，用于记录岛屿数量。
//    - 遍历二维网格 grid 的每个单元格。
//    - 当遇到一个值为 '1' 的单元格时，表示发现了一个新的岛屿，计数器 count 增加 1。
//    - 调用 dfs 函数，从当前单元格开始，标记整个岛屿的所有陆地单元格为 '0'，表示它们已被访问过。
// 2. 辅助函数 dfs:
//    - 接受当前单元格的坐标 (i, j) 作为参数。
//    - 首先检查当前单元格是否越界或是否为水域 ('0')。如果是，则返回，结束当前递归调用。
//    - 将当前单元格标记为 '0'，表示该单元格已被访问过。
//    - 递归调用 dfs 函数，分别向上、下、左、右四个方向探索相邻的单元格。
// 通过这种方式，DFS 方法能够有效地遍历和标记每个岛屿，确保每个岛屿只被计数一次，从而正确计算出岛屿的总数量。
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';  // Mark as visited
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}
