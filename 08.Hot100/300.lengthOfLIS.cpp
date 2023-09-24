//
// Created by huangxin on 2023/9/23.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        vector<vector<int>> all_longest_lis;
//        for (int i = 0; i < nums.size(); i++) {
//            vector<vector<int>> all_lis;
//            int curr = nums[i];
//            for (int j = 1; j < nums.size()-1-i; ++j) {
//                vector<int> lis;
//                lis.push_back(curr);
//                for (int k = i+j; k < nums.size(); k++) {
//                    if (nums[k] > curr) {
//                        curr = nums[k];
//                        lis.push_back(curr);
//                    }
//                }
//                all_lis.push_back(lis);
//            }
//
//            pair<int, int> recorder = {0, 0};
//            for (int i = 0;  i < all_lis.size(); i++) {
//                if(all_lis[i].size() >= recorder.first) {
//                    recorder.first = all_lis[i].size();
//                    recorder.second = i;
//                }
//            }
//            all_longest_lis.push_back(all_lis[recorder.second]);
//        }
//        int max_len = 0;
//        for (int i = 0; i < all_longest_lis.size(); i++) {
//            if(all_longest_lis[i].size() > max_len) {
//                max_len = all_longest_lis[i].size();
//            }
//        }
//        return max_len;
//    }
//};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int max_len = 0;
        vector<int> dp(nums.size()+1, 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > max_len) {
                max_len = dp[i];
            }
        }
        return max_len;
    }
};


int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution solution;
    int res = solution.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}