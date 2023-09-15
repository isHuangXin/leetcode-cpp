//
// Created by huangxin on 2023/8/18.
//

#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<vector<int>>& matrix) {
    int maxElement = INT_MIN;
    for (const auto& row : matrix) {
        if (!row.empty()) {
            maxElement = max(maxElement, row.back());
        }
    }
    return maxElement;
}

int main() {
    vector<vector<int>> matrix = {
            {2, 5, 9},
            {3, 7, 12},
            {1, 4, 8},
            {10, 11, 15},
            {6, 13, 14},
    };

    int maxElement = findMax(matrix);
    cout << "最大的元素是: " << maxElement << endl;

    return 0;
}
