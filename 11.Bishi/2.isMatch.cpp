//
// Created by huangxin on 2023/9/26.
//
#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();

    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

    dp[0][0] = true;

    for (int j = 0; j <= n; j++) {
        if (p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (p[j-1] == s[i-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] == '*'){
                dp[i][j] == dp[i][j-2] || (dp[i-1][j]&&(s[i-1] == p[j-2] || p[j-2] == '.'));
            }
        }
    }
    return dp[m][n];
}

int main () {
    string s, p;
    cin >> s >> p;

    if (isMatch(s, p)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}