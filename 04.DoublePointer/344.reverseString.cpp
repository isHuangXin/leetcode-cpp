// Problem: 344.反转字符串
// Link: https://leetcode.cn/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int left=0, right=n-1; left<right; left++, right--) {
            swap(s[left], s[right]);
            // int temp = s[left];
            // s[left] = s[right];
            // s[right] = temp;
        }
    }
};