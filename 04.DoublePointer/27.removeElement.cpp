// Problem: 27.移除元素
// Link: https://leetcode.cn/problems/remove-element/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针法：左右指针最初在同一位置
        int left = 0;
        for(int right=0; right<nums.size(); right++) {
            if(nums[right]!=val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};