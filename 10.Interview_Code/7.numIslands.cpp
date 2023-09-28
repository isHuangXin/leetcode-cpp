//
// Created by huangxin on 2023/9/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r-1 >=0 && grid[r-1][c] == '1') {
            dfs(grid, r-1, c);
        }
        if (r+1 < nr && grid[r+1][c] == '1') {
            dfs(grid, r+1, c);
        }
        if (c-1 >= 0 && grid[r][c-1] == '1') {
            dfs(grid, r, c-1);
        }
        if (c+1 < nc && grid[r][c+1] == '1') {
            dfs(grid, r, c+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };
    Solution solution;
    int res = solution.numIslands(grid);
    cout << res << endl;
    return 0;
}