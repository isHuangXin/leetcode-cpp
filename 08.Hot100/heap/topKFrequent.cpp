#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int num: nums) {
            freqMap[num]++;
        }

        vector<pair<int, int>> freqVec;
        for(const auto& entry: freqMap) {
            freqVec.emplace_back(entry.first, entry.second);
        }

        // sort the vector based on frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>&a, const pair<int, int>&b) {
            return a.second > b.second;
        });

        // collect the top k frequent elements
        vector<int> result;
        for(int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }
        
        return result;
    }
};
