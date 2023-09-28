//
// Created by huangxin on 2023/9/28.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for (int j = 2; j < n; j++) {
            
        }


    }
};

int main() {
    string s, p;
    cin >> s >> p;
    Solution solution;
    bool res = solution.isMatch(s, p);
    if (res) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}