//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> minStep(int m, int n, vector<string>& string_map, vector<vector<int>>& index_matrix) {
    for (int i = 0; i < index_matrix.size(); ++i) {
        pair<int, int> start;
        pair<int, int> end;
        start.first = index_matrix[i][0];
        start.second = index_matrix[i][1];
        end.first = index_matrix[i][2];
        end.second = index_matrix[i][3];
        vector<vector<int>>
    }
}


int main() {
    int m, n;
    cin >> m >> n;
    vector<string> string_map;
    for (int i = 0; i < m; i++) {
        string row_string;
        cin >> row_string;
        string_map.push_back(row_string);
    }
    int q;
    cin >> q;
    vector<vector<int>> index_matrix;
    for (int i = 0; i < q; i++) {
        vector<int> status;
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            status.push_back(temp);
        }
        index_matrix.push_back(status);
    }
    vector<int> res = minStep(m, n, string_map, index_matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}