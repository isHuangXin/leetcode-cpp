class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // 哈希方法的关键词：小写字符，出现频率
        vector<string> result;
        int hash[26] = {0};
        int hashOtherStr[26] = {0};
        if (words.size() == 0) {
            return result;
        }
        // 用第一个字符串给hash初始化
        for (int i=0; i<words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }

        for (int i=1; i<words.size(); i++) {
            memset(hashOtherStr, 0, 26 * sizeof(int));
            for (int j=0; j<words[i].size(); j++) {
                hashOtherStr[words[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hashOtherStr[k]);
            }
        }

        for (int i=0; i<26; i++) {
            while (hash[i] != 0) {
                string s(1, i + 'a');
                result.push_back(s);
                hash[i]--;
            }
        }
        return result;
    }
};