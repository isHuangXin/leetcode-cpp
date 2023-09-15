// Problem: 202.快乐数
// Link: https://leetcode.cn/problems/happy-number/
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sum(int n) {
        int sum = 0;
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> res;
        while(1) {
            int num = sum(n);
            if (num == 1) {
                return true;
            }
            if (res.find(num) != res.end()) {
                return false;
            } else {
                // unordered_set 添加元素用 .emplace() 方法
                res.emplace(num);
            }
            n = num;
        }
    }
};