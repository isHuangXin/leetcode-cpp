// Problem: 454.四数之和
// Link: https://leetcode.cn/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 思路: 两个数分为一组 + 哈希
        int ans = 0;
        unordered_map<int, int> hashTable;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                hashTable[nums1[i] + nums2[j]]++;
            }
        }
        
        for(int i=0; i<nums3.size(); i++) {
            for(int j=0; j<nums4.size(); j++) {
                int target = 0 - (nums3[i] + nums4[j]);
                auto it = hashTable.find(target);
                if (it != hashTable.end()) {
                    // why ans += hashTable[target]
                    // 而不是 ans += hashTable[target]
                    // 因为: 要记录的是出现的次数，而hashTable[target]正好记录的是次数
                    ans += hashTable[target]; 
                }
            }
        }
        return ans;
    }
};
