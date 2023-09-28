//
// Created by huangxin on 2023/9/27.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int allsum = 1;
        int res = 1;
        int count = 0;
        int maxSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                res = 1;
            }
            allsum *= nums[i];
            res *= nums[i];
            maxSum = max(maxSum, res);
            maxSum = max(allsum, maxSum);
            count++;
        }
        return maxSum;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution solution;
    int res = solution.maxProduct(nums);
    cout << res << endl;
    return 0;
}