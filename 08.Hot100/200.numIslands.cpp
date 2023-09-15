//
// Created by huangxin on 2023/9/15.
//

// dfs
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();
    grid[r][c] = '0';
    if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
    if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
    if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
    if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
}

int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (nr == 0) {
        return 0;
    }
    int nc = grid[0].size();

    int lands_number = 0;
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (grid[i][j] == '1') {
                lands_number++;
                dfs(grid, i, j);
            }
        }
    }
    return lands_number;
}


int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
    };
    cout << numIslands(grid) << endl;
    return 0;
}


// bfs