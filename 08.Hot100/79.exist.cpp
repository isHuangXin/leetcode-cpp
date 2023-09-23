//
// Created by huangxin on 2023/9/15.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int current_len, vector<vector<bool>>& visited) {
        if (current_len == word.size()) {
            return true;
        }

        int nr = board.size();
        int nc = board[0].size();

        // 检查当前单元格是否越界，是否已经访问过，以及是否匹配单词的当前字符
        if (r < 0 || r >= nr || c < 0 || c >= nc || visited[r][c] || board[r][c] != word[current_len]) {
            return false;
        }

        // 标记当前单元格为已访问
        visited[r][c] = true;

        // 递归搜索上、下、左、右四个方向
        bool found = dfs(board, word, r - 1, c, current_len + 1, visited) ||
                     dfs(board, word, r + 1, c, current_len + 1, visited) ||
                     dfs(board, word, r, c - 1, current_len + 1, visited) ||
                     dfs(board, word, r, c + 1, current_len + 1, visited);

        // 恢复当前单元格的未访问状态，以便在其他路径中继续使用
        visited[r][c] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int nr = board.size();
        if (nr == 0) {
            return false;
        }
        int nc = board[0].size();

        // 创建一个二维数组来记录访问状态
        vector<vector<bool>> visited(nr, vector<bool>(nc, false));

        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    Solution solution;
    if (solution.exist(board, word)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
