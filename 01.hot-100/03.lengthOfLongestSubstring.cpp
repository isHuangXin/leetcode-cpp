//
// Created by huangxin on 1/16/22.
//

#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_set<char> lookup;
        int maxNum = 0, left = 0;
        for (int i = 0; i<s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left++;
            }
            maxNum = max(maxNum, i-left+1);
            lookup.insert(s[i]);
        }
        return maxNum;
    }
};

int main(){
    Solution substring;
    string s = "abcabcbb";
    substring.lengthOfLongestSubstring(s);
    return 0;
}