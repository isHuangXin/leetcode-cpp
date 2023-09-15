// Problem: 18.四数之和
// Link: https://leetcode.cn/problems/4sum/

// Note: 还有bug
// Line 42: Char 9: error: expected member name or ';' after declaration specifiers
//          return res;
//          ^

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};

//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>> res;
//        int n = nums.size();
//        sort(nums.begin(), nums.end());
//        if(n < 4) {
//            return res;
//        }
//
//        int first, second, third, fourth;
//        for(first=0; first<=n-4; first++) {
//            // 保证第一个数不重复
//            if(first>0 && nums[first] == nums[first-1]) {
//                continue;
//            }
//            for (second=first+1; second<=n-3; second++) {
//                // 保证第二个数不重复
//                if(second>first+1 && nums[second]==nums[second-1]) {
//                    continue;
//                }
//                int third=second+1, fourth=n-1;
//                while(third < fourth) {
//                    if(nums[first]+nums[second]-target<-(nums[third]+nums[fourth])) {
//                        third++;
//                    } else if(nums[first]+nums[second]-target>-(nums[third]+nums[fourth]))//同上
//        			    fourth--;
//                    } else {
//                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});
//                        while (third<fourth && nums[third]== nums[third+1]){
//                            third++;
//                        }
//                        while (third<fourth && nums[fourth-1] == nums[fourth]) {
//                            fourth--;
//                        }
//                        third++;
//                        fourth--;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};