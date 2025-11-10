#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
    // 值 0 代表空单元格；
    // 值 1 代表新鲜橘子；
    // 值 2 代表腐烂的橘子。
    // 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
    // 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
    // 请你帮我实现这个代码
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;
        bool changed;

        do {
            changed = false;
            vector<vector<int>> newGrid = grid;

            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (grid[r][c] == 2) {
                        for (const auto& dir : directions) {
                            int newRow = r + dir.first;
                            int newCol = c + dir.second;
                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                                newGrid[newRow][newCol] = 2;
                                changed = true;
                            }
                        }
                    }
                }
            }

            if (changed) {
                minutes++;
                grid = newGrid;
            }
        } while (changed);

        // 是什么意思
        // 这段代码的目的是检查是否还有新鲜橘子存在
        // 如果存在，说明无法将所有橘子都腐烂，返回 -1
        // 否则，返回所需的分钟数
        // 遍历整个网格，检查是否还有值为 1 的单元格（新鲜橘子）
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 1) {
                    return -1;
                }
            }
        }

        return minutes;

    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int result = sol.orangesRotting(grid);
    cout << result << endl;
    return 0;
}
