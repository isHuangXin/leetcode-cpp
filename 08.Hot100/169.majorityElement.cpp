//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> unorderedMap;
        for (int i = 0; i < nums.size(); ++i) {
            unorderedMap[nums[i]] += 1;
        }
        int res;
        for (auto it = unorderedMap.begin(); it != unorderedMap.end() ; it++) {
            if(it->second > ceil(nums.size()/2)) {
                res = it->first;
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {6,5,5};
    Solution solution;
    int res = solution.majorityElement(nums);
    cout << res << endl;
    return 0;
}