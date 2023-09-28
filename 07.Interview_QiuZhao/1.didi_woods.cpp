//
// Created by huangxin on 2023/9/28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTriangle(int a, int b, int c) {
    return a+b > c && a+c > b && b+c>a;
}

int numGoodTriangle(int n, int a, int b, int c) {
    if (n == 0) {
        if (isTriangle(a,b,c)) {
            return 1;
        }
        return 0;
    }

    vector<int> nums(3);
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;
    sort(nums.begin(), nums.end());

    vector<vector<int>> permutation_nums;
    do {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        permutation_nums.push_back(temp);
    } while (next_permutation(nums.begin(), nums.end()));

    int res = 0;
    vector<vector<int>> all_res;
    for (int j = 0; j < permutation_nums.size(); j++) {
        int new_a = permutation_nums[j][0], new_b = permutation_nums[j][1], new_c = permutation_nums[j][2];
        for (int i = 0; i < n; i++) {
            vector<int> temp_res;
            if ((new_a-i > 0) && (new_b-i-1 > 0) && (new_c-i-2 > 0)) {
                if (isTriangle(new_a, new_b, new_c)) {
                    temp_res.push_back(new_a-i);
                    temp_res.push_back(new_b-i-1);
                    temp_res.push_back(new_c-i-2);
                    res += 1;
                }
            }
            if (temp_res.size() != 0) {
                all_res.push_back(temp_res);
            }
            int new_a = permutation_nums[j][0], new_b = permutation_nums[j][1], new_c = permutation_nums[j][2];
        }
    }
    return res;
}

int main () {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int res = numGoodTriangle(n, a, b, c);
    cout << res << endl;
    return 0;
}