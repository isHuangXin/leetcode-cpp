// Problem: 383.赎金信
// Link: https://leetcode.cn/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ans[26] = {0};
        // 记录magazine中每个字符出现的次数
        for(int i=0; i<magazine.size(); i++) {
            ans[magazine[i] - 'a']++;
        }
        // 统计每个字符在ransomNote中出现的次数是否小于在magazine中出现的次数
        for(int j=0; j<ransomNote.size(); j++) {
            ans[ransomNote[j] - 'a']--;
            if(ans[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};