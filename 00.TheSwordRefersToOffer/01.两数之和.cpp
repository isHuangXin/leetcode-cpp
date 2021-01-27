//
// Created by Huangxin's macbook air on 1/27/21.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            auto iter = hashtable.find(target - nums[i]);
            if(iter != hashtable.end()){
                res.push_back(iter->second);
                res.push_back(i);
                return res;
            }
            hashtable[nums[i]] = i;
        }
        return res;
    }
};

int main(){
    Solution solution;
    int num[4] = {2, 7, 11, 15}, target = 9;
    vector<int> nums;
    cout<<"sizeof(num): "<< sizeof(num)<<endl;
    cout<<"sizeof(num[0]): "<< sizeof(num[0])<<endl;
    cout<<"sizeof(num)/ sizeof(num[0]): "<< sizeof(num)/ sizeof(num[0])<<endl;
    for(int i=0; i< sizeof(num)/ sizeof(num[0]); i++){
        nums.push_back(num[i]);
    }
    vector<int> res = solution.twoSum(nums, target);
    cout<< res[0]<<" "<<res[1]<<endl;
    return 0;

}
