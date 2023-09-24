//
// Created by huangxin on 2023/9/24.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int>&a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> unorderedMap;
        for (int i = 0; i < nums.size(); ++i) {
            unorderedMap[nums[i]] += 1;
        }

        vector<pair<int, int>> frequency;
        for (auto it = unorderedMap.begin(); it != unorderedMap.end() ; it++) {
            pair<int, int> freq;
            freq.first = it->first;
            freq.second = it->second;
            frequency.push_back(freq);
        }
        sort(frequency.begin(), frequency.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(frequency[i].first);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution solution;
    vector<int> res = solution.topKFrequent(nums, k);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}