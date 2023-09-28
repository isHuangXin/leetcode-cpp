//
// Created by huangxin on 2023/9/26.
//
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5;

bool cmp(int a, int b) {
    return a > b;
}

int minWoodsNum(vector<int>& woods, int target) {
    if(woods.size() == 0) {
        return -1;
    }
    if (woods.size() == 1 && woods[0] != target) {
        return -1;
    }

    sort(woods.begin(), woods.end(), cmp);
    int sum = 0;
    int count = 0;
    for (int i = 0; i < woods.size(); i++) {
        if (sum == target) {
            return woods.size() - count;
        }
        count += 1;
        sum += woods[i];
    }

    int n = woods.size();
    vector<long long> dp(target+1, INF);
    dp[0] = 0;
    for (int i = 0; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i-woods[j] >= 0) {
                dp[i] = min(dp[i], dp[i-woods[j]]+1);
            }
        }
    }

    return dp[target] == INF ? -1 : dp[target];
}

int main() {
    vector<int> woods;
    int wood;
    while (cin >> wood) {
        woods.push_back(wood);
    }
    int target;
    cin >> target;
    int minNum = minWoodsNum(woods, target);
    cout << minNum << endl;
    return 0;
}