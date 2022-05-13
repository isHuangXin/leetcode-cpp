//
// Created by huangxin on 5/13/22.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i=0; i< rows; i++){
            for(int j=0; j < cols; j++){
                if(DFS(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int rows, cols;
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
            return false;
        if(k==word.size() - 1)
            return true;
        board[i][j] = '\0';
        bool res = DFS(board, word, i+1, j, k+1) || DFS(board, word, i-1, j, k+1)
                || DFS(board, word, i, j+1, k+1) || DFS(board, word, i, j-1, k+1);
        board[i][j] = word[k];
        return res;
    }
};


int main(){
    vector<vector<char>> board = {{'a', 'b', 'c', 'd'},
                                  {'s', 'f', 'c', 's'},
                                  {'a', 'd', 'e', 'f'}};
    string word = "ABCCED";
    Solution solution;
    bool res = solution.exist(board, word);
    cout<< res;
    return 0;

}