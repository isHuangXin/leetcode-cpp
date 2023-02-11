// Problem: 18.四数之和
// Link: https://leetcode.cn/problems/4sum/

// Note: 还有bug
// Line 42: Char 9: error: expected member name or ';' after declaration specifiers
//          return res;
//          ^
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n < 4) {
            return res;
        }
        
        int first, second, third, fourth;
        for(first=0; first<=n-4; first++) {
            // 保证第一个数不重复
            if(first>0 && nums[first] == nums[first-1]) {
                continue;
            }
            for (second=first+1; second<=n-3; second++) {
                // 保证第二个数不重复
                if(second>first+1 && nums[second]==nums[second-1]) {
                    continue;
                }
                int third=second+1, fourth=n-1;
                while(third < fourth) {
                    if(nums[first]+nums[second]-target<-(nums[third]+nums[fourth])) {
                        third++;
                    } else if(nums[first]+nums[second]-target>-(nums[third]+nums[fourth]))//同上
        			    fourth--;
                    } else {
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while (third<fourth && nums[third]== nums[third+1]){
                            third++;
                        }
                        while (third<fourth && nums[fourth-1] == nums[fourth]) {
                            fourth--;
                        }
                        third++;
                        fourth--;
                    }
                }
            }
        }
        return res;
    }
};